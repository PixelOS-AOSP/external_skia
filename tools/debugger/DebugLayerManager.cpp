/*
 * Copyright 2019 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "tools/debugger/DebugLayerManager.h"

#include "include/core/SkImage.h"
#include "include/core/SkImageInfo.h"
#include "include/core/SkPicture.h"
#include "include/core/SkSurface.h"
#include "include/private/SkTHash.h"
#include "tools/debugger/DebugCanvas.h"

#include <memory>
#include <vector>
#include <tuple>

void DebugLayerManager::setCommand(int nodeId, int frame, int command) {
  auto* drawEvent = fDraws.find({frame, nodeId});
  if (!drawEvent) {
    SkDebugf("Could not set command playhead for event {%d, %d}, it is not tracked by"
      "DebugLayerManager.\n", frame, nodeId);
    return;
  }
  const int count = drawEvent->debugCanvas->getSize();
  drawEvent->command = command < count ? command : count - 1;
  // Invalidate stored images that depended on this combination of node and frame.
  // actually this does all of the events for this nodeId, but close enough.
  auto relevantFrames = listFramesForNode(nodeId);
  for (const auto& frame : relevantFrames) {
    fDraws[{frame, nodeId}].image = nullptr;
  }
}

void DebugLayerManager::storeSkPicture(int nodeId, int frame, sk_sp<SkPicture> picture,
    SkIRect dirty) {
  const LayerKey k = {frame, nodeId};

  // Make debug canvas using bounds from SkPicture. This will be equal to whatever width and
  // height were passed into SkPictureRecorder::beginRecording(w, h) which is the layer bounds.
  const auto& layerBounds = picture->cullRect().roundOut();
  auto debugCanvas = std::make_unique<DebugCanvas>(layerBounds);
  // Must be set or they end up undefined due to cosmic rays, bad luck, etc.
  debugCanvas->setOverdrawViz(false);
  debugCanvas->setDrawGpuOpBounds(false);
  debugCanvas->setClipVizColor(SK_ColorTRANSPARENT);
  // Setting this allows a layer to contain another layer. TODO(nifong): write a test for this.
  debugCanvas->setLayerManagerAndFrame(this, frame);
  // Only draw picture to the debug canvas once.
  debugCanvas->drawPicture(picture);
  int numCommands = debugCanvas->getSize();

  DrawEvent event = {
    frame == 0 || dirty==layerBounds,            // fullRedraw
    nullptr,                                      // image
    std::move(debugCanvas),                       // debugCanvas
    numCommands-1,                                // command
    {layerBounds.height(), layerBounds.width()},  // layerBounds
  };

  fDraws.set(k, std::move(event));
  keys.push_back(k);
}

sk_sp<SkImage> DebugLayerManager::getLayerAsImage(const int nodeId, const int frame) {
  // What is the last frame having an SkPicture for this layer? call it frame N
  // have cached image of it? if so, return it.
  // if not, draw it at frame N by the following method:
  // The picture at frame N could have been a full redraw, or it could have been clipped to a
  // dirty region. In order to know what the layer looked like on this frame, we must draw every
  // picture starting with the last full redraw, up to the last one before the current frame, since
  // any of those previous draws could be showing through.

  // list of frames this node was updated on.
  auto relevantFrames = listFramesForNode(nodeId);
  // find largest one not greater than `frame`.
  uint32_t i = relevantFrames.size()-1;
  while (relevantFrames[i] > frame) { i--; }
  const int frameN = relevantFrames[i];
  // Fetch the draw event
  auto& drawEvent = fDraws[{frameN, nodeId}];
  // if an image of this is cached, return it.
  if (drawEvent.image) {
    return drawEvent.image;
  }
  // when it's not cached, we'll have to render it in an offscreen surface.
  // start at the last full redraw. (pick up counting backwards from above)
  while (i>0 && !(fDraws[{relevantFrames[i], nodeId}].fullRedraw)) { i--; }
  // The correct layer bounds can be obtained from any drawEvent on this layer.
  // the color type and alpha type are chosen here to match wasm-skp-debugger/cpu.js which was
  // chosen to match the capabilities of HTML canvas, which this ultimately has to be drawn into.
  // TODO(nifong): introduce a method of letting the user choose the backend for this.
  auto surface = SkSurface::MakeRaster(SkImageInfo::Make(drawEvent.layerBounds,
    kRGBA_8888_SkColorType, kUnpremul_SkAlphaType, nullptr));
  // draw everything from the last full redraw up to the current frame.
  // other frames drawn are partial, meaning they were clipped to not completely cover the layer.
  // count back up with i
  auto* canvas = surface->getCanvas();
  for (; i<relevantFrames.size() && relevantFrames[i]<=frameN; i++) {
    auto& evt = fDraws[{relevantFrames[i], nodeId}];
    evt.debugCanvas->drawTo(canvas, evt.command);
    canvas->flush();
  }
  drawEvent.image = surface->makeImageSnapshot();
  return drawEvent.image;
}

std::vector<DebugLayerManager::DrawEventSummary> DebugLayerManager::summarizeEvents(int frame) const {
    std::vector<DrawEventSummary> result;
  for (const auto& node : listNodesForFrame(frame)) {
    auto* evt = fDraws.find({frame, node});
    if (!evt) { continue; }
    result.push_back({
      node, evt->fullRedraw, evt->debugCanvas->getSize(),
      evt->layerBounds.width(), evt->layerBounds.height()
    });
  }
  return result;
}

std::vector<int> DebugLayerManager::listNodesForFrame(int frame) const {
  std::vector<int> result;
  for (const auto& key : keys) {
    if (key.frame == frame) {
      result.push_back(key.nodeId);
    }
  }
  return result;
}

std::vector<int> DebugLayerManager::listFramesForNode(int nodeId) const {
  std::vector<int> result;
  for (const auto& key : keys) {
    if (key.nodeId == nodeId) {
      result.push_back(key.frame);
    }
  }
  return result;
}
