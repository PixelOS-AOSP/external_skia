/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * THIS FILE IS AUTOGENERATED
 * Make edits to tools/gpu/gl/interface/templates.go or they will
 * be overwritten.
 */

#include "include/gpu/gl/GrGLExtensions.h"
#include "include/gpu/gl/GrGLInterface.h"
#include "src/gpu/gl/GrGLUtil.h"

#include <stdio.h>

GrGLInterface::GrGLInterface() {
    fStandard = kNone_GrGLStandard;
}

#if GR_GL_CHECK_ERROR
static const char* get_error_string(GrGLenum err) {
    switch (err) {
        case GR_GL_NO_ERROR:
            return "";
        case GR_GL_INVALID_ENUM:
            return "Invalid Enum";
        case GR_GL_INVALID_VALUE:
            return "Invalid Value";
        case GR_GL_INVALID_OPERATION:
            return "Invalid Operation";
        case GR_GL_OUT_OF_MEMORY:
            return "Out of Memory";
        case GR_GL_CONTEXT_LOST:
            return "Context Lost";
    }
    return "Unknown";
}

GrGLenum GrGLInterface::checkError(const char* location, const char* call) const {
    GrGLenum error = fFunctions.fGetError();
    if (error != GR_GL_NO_ERROR && !fSuppressErrorLogging) {
        SkDebugf("---- glGetError 0x%x(%s)", error, get_error_string(error));
        if (location) {
            SkDebugf(" at\n\t%s", location);
        }
        if (call) {
            SkDebugf("\n\t\t%s", call);
        }
        SkDebugf("\n");
        if (error == GR_GL_OUT_OF_MEMORY) {
            fOOMed = true;
        }
    }
    return error;
}

bool GrGLInterface::checkAndResetOOMed() const {
    if (fOOMed) {
        fOOMed = false;
        return true;
    }
    return false;
}

void GrGLInterface::suppressErrorLogging() { fSuppressErrorLogging = true; }
#endif

#define RETURN_FALSE_INTERFACE                                                 \
    SkDEBUGF("%s:%d GrGLInterface::validate() failed.\n", __FILE__, __LINE__); \
    return false

bool GrGLInterface::validate() const {

    if (kNone_GrGLStandard == fStandard) {
        RETURN_FALSE_INTERFACE;
    }

    if (!fExtensions.isInitialized()) {
        RETURN_FALSE_INTERFACE;
    }

    GrGLVersion glVer = GrGLGetVersion(this);
    if (GR_GL_INVALID_VER == glVer) {
        RETURN_FALSE_INTERFACE;
    }
    // Autogenerated content follows
    if (!fFunctions.fActiveTexture ||
        !fFunctions.fAttachShader ||
        !fFunctions.fBindAttribLocation ||
        !fFunctions.fBindBuffer ||
        !fFunctions.fBindTexture ||
        !fFunctions.fBlendColor ||
        !fFunctions.fBlendEquation ||
        !fFunctions.fBlendFunc ||
        !fFunctions.fBufferData ||
        !fFunctions.fBufferSubData ||
        !fFunctions.fClear ||
        !fFunctions.fClearColor ||
        !fFunctions.fClearStencil ||
        !fFunctions.fColorMask ||
        !fFunctions.fCompileShader ||
        !fFunctions.fCompressedTexImage2D ||
        !fFunctions.fCompressedTexSubImage2D ||
        !fFunctions.fCopyTexSubImage2D ||
        !fFunctions.fCreateProgram ||
        !fFunctions.fCreateShader ||
        !fFunctions.fCullFace ||
        !fFunctions.fDeleteBuffers ||
        !fFunctions.fDeleteProgram ||
        !fFunctions.fDeleteShader ||
        !fFunctions.fDeleteTextures ||
        !fFunctions.fDepthMask ||
        !fFunctions.fDisable ||
        !fFunctions.fDisableVertexAttribArray ||
        !fFunctions.fDrawArrays ||
        !fFunctions.fDrawElements ||
        !fFunctions.fEnable ||
        !fFunctions.fEnableVertexAttribArray ||
        !fFunctions.fFinish ||
        !fFunctions.fFlush ||
        !fFunctions.fFrontFace ||
        !fFunctions.fGenBuffers ||
        !fFunctions.fGenTextures ||
        !fFunctions.fGetBufferParameteriv ||
        !fFunctions.fGetError ||
        !fFunctions.fGetIntegerv ||
        !fFunctions.fGetProgramInfoLog ||
        !fFunctions.fGetProgramiv ||
        !fFunctions.fGetShaderInfoLog ||
        !fFunctions.fGetShaderiv ||
        !fFunctions.fGetString ||
        !fFunctions.fGetUniformLocation ||
        !fFunctions.fIsTexture ||
        !fFunctions.fLineWidth ||
        !fFunctions.fLinkProgram ||
        !fFunctions.fPixelStorei ||
        !fFunctions.fReadPixels ||
        !fFunctions.fScissor ||
        !fFunctions.fShaderSource ||
        !fFunctions.fStencilFunc ||
        !fFunctions.fStencilFuncSeparate ||
        !fFunctions.fStencilMask ||
        !fFunctions.fStencilMaskSeparate ||
        !fFunctions.fStencilOp ||
        !fFunctions.fStencilOpSeparate ||
        !fFunctions.fTexImage2D ||
        !fFunctions.fTexParameterf ||
        !fFunctions.fTexParameterfv ||
        !fFunctions.fTexParameteri ||
        !fFunctions.fTexParameteriv ||
        !fFunctions.fTexSubImage2D ||
        !fFunctions.fUniform1f ||
        !fFunctions.fUniform1fv ||
        !fFunctions.fUniform1i ||
        !fFunctions.fUniform1iv ||
        !fFunctions.fUniform2f ||
        !fFunctions.fUniform2fv ||
        !fFunctions.fUniform2i ||
        !fFunctions.fUniform2iv ||
        !fFunctions.fUniform3f ||
        !fFunctions.fUniform3fv ||
        !fFunctions.fUniform3i ||
        !fFunctions.fUniform3iv ||
        !fFunctions.fUniform4f ||
        !fFunctions.fUniform4fv ||
        !fFunctions.fUniform4i ||
        !fFunctions.fUniform4iv ||
        !fFunctions.fUniformMatrix2fv ||
        !fFunctions.fUniformMatrix3fv ||
        !fFunctions.fUniformMatrix4fv ||
        !fFunctions.fUseProgram ||
        !fFunctions.fVertexAttrib1f ||
        !fFunctions.fVertexAttrib2fv ||
        !fFunctions.fVertexAttrib3fv ||
        !fFunctions.fVertexAttrib4fv ||
        !fFunctions.fVertexAttribPointer ||
        !fFunctions.fViewport) {
        RETURN_FALSE_INTERFACE;
    }

    if (GR_IS_GR_GL(fStandard)) {
        if (!fFunctions.fDrawBuffer ||
            !fFunctions.fPolygonMode) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(3,0)))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0)))) ||
       (GR_IS_GR_WEBGL(fStandard) && (
          (glVer >= GR_GL_VER(2,0))))) {
        if (!fFunctions.fGetStringi) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(4,2)))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,1))))) {
        // all functions were marked optional or test_only
    }

    if (GR_IS_GR_GL(fStandard) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0)) ||
          fExtensions.has("GL_OES_vertex_array_object"))) ||
       (GR_IS_GR_WEBGL(fStandard) && (
          (glVer >= GR_GL_VER(2,0)) ||
          fExtensions.has("GL_OES_vertex_array_object") ||
          fExtensions.has("OES_vertex_array_object")))) {
        if (!fFunctions.fBindVertexArray ||
            !fFunctions.fDeleteVertexArrays ||
            !fFunctions.fGenVertexArrays) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(4,0)) ||
          fExtensions.has("GL_ARB_tessellation_shader"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,2)) ||
          fExtensions.has("GL_OES_tessellation_shader")))) {
        if (!fFunctions.fPatchParameteri) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(3,0)))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0) && fExtensions.has("GL_EXT_blend_func_extended"))))) {
        if (!fFunctions.fBindFragDataLocation) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(3,3)) ||
          fExtensions.has("GL_ARB_blend_func_extended"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0) && fExtensions.has("GL_EXT_blend_func_extended"))))) {
        if (!fFunctions.fBindFragDataLocationIndexed) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          fExtensions.has("GL_KHR_blend_equation_advanced") ||
          fExtensions.has("GL_NV_blend_equation_advanced"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_KHR_blend_equation_advanced") ||
          fExtensions.has("GL_NV_blend_equation_advanced")))) {
        if (!fFunctions.fBlendBarrier) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(4,4)) ||
          fExtensions.has("GL_ARB_clear_texture"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_EXT_clear_texture")))) {
        // all functions were marked optional or test_only
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(3,1)) ||
          fExtensions.has("GL_ARB_draw_instanced") ||
          fExtensions.has("GL_EXT_draw_instanced"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0)) ||
          fExtensions.has("GL_EXT_draw_instanced"))) ||
       (GR_IS_GR_WEBGL(fStandard) && (
          (glVer >= GR_GL_VER(2,0))))) {
        if (!fFunctions.fDrawArraysInstanced ||
            !fFunctions.fDrawElementsInstanced) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(4,2)) ||
          fExtensions.has("GL_ARB_base_instance"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_EXT_base_instance") ||
          fExtensions.has("GL_ANGLE_base_vertex_base_instance")))) {
        if (!fFunctions.fDrawArraysInstancedBaseInstance ||
            !fFunctions.fDrawElementsInstancedBaseVertexBaseInstance) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if (GR_IS_GR_GL(fStandard) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0)))) ||
       (GR_IS_GR_WEBGL(fStandard) && (
          (glVer >= GR_GL_VER(2,0))))) {
        if (!fFunctions.fDrawBuffers ||
            !fFunctions.fReadBuffer) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(4,0)) ||
          fExtensions.has("GL_ARB_draw_indirect"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,1))))) {
        if (!fFunctions.fDrawArraysIndirect ||
            !fFunctions.fDrawElementsIndirect) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_ANGLE_base_vertex_base_instance")))) {
        if (!fFunctions.fMultiDrawArraysInstancedBaseInstance ||
            !fFunctions.fMultiDrawElementsInstancedBaseVertexBaseInstance) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if (GR_IS_GR_GL(fStandard) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0)))) ||
       (GR_IS_GR_WEBGL(fStandard) && (
          (glVer >= GR_GL_VER(2,0))))) {
        if (!fFunctions.fDrawRangeElements) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(3,2)) ||
          fExtensions.has("GL_ARB_texture_multisample"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,1))))) {
        if (!fFunctions.fGetMultisamplefv) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if (GR_IS_GR_GL(fStandard) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,1))))) {
        if (!fFunctions.fGetTexLevelParameteriv) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(4,3)) ||
          fExtensions.has("GL_ARB_multi_draw_indirect"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_EXT_multi_draw_indirect")))) {
        if (!fFunctions.fMultiDrawArraysIndirect ||
            !fFunctions.fMultiDrawElementsIndirect) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(3,1)))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,2)) ||
          fExtensions.has("GL_OES_texture_buffer") ||
          fExtensions.has("GL_EXT_texture_buffer")))) {
        if (!fFunctions.fTexBuffer) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(4,3)))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,2)) ||
          fExtensions.has("GL_OES_texture_buffer") ||
          fExtensions.has("GL_EXT_texture_buffer")))) {
        if (!fFunctions.fTexBufferRange) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(4,2)) ||
          fExtensions.has("GL_ARB_texture_storage") ||
          fExtensions.has("GL_EXT_texture_storage"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0)) ||
          fExtensions.has("GL_EXT_texture_storage"))) ||
       (GR_IS_GR_WEBGL(fStandard) && (
          (glVer >= GR_GL_VER(2,0))))) {
        if (!fFunctions.fTexStorage2D) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(4,5)) ||
          fExtensions.has("GL_ARB_texture_barrier") ||
          fExtensions.has("GL_NV_texture_barrier"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_NV_texture_barrier")))) {
        if (!fFunctions.fTextureBarrier) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_EXT_discard_framebuffer")))) {
        if (!fFunctions.fDiscardFramebuffer) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_QCOM_tiled_rendering")))) {
        // all functions were marked optional or test_only
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(3,2)) ||
          fExtensions.has("GL_ARB_instanced_arrays"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0)) ||
          fExtensions.has("GL_EXT_instanced_arrays"))) ||
       (GR_IS_GR_WEBGL(fStandard) && (
          (glVer >= GR_GL_VER(2,0))))) {
        if (!fFunctions.fVertexAttribDivisor) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(3,0)))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0)))) ||
       (GR_IS_GR_WEBGL(fStandard) && (
          (glVer >= GR_GL_VER(2,0))))) {
        if (!fFunctions.fVertexAttribIPointer) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(3,0)) ||
          fExtensions.has("GL_ARB_framebuffer_object") ||
          fExtensions.has("GL_EXT_framebuffer_object"))) ||
       GR_IS_GR_GL_ES(fStandard) ||
       GR_IS_GR_WEBGL(fStandard)) {
        if (!fFunctions.fBindFramebuffer ||
            !fFunctions.fBindRenderbuffer ||
            !fFunctions.fCheckFramebufferStatus ||
            !fFunctions.fDeleteFramebuffers ||
            !fFunctions.fDeleteRenderbuffers ||
            !fFunctions.fFramebufferRenderbuffer ||
            !fFunctions.fFramebufferTexture2D ||
            !fFunctions.fGenFramebuffers ||
            !fFunctions.fGenRenderbuffers ||
            !fFunctions.fGenerateMipmap ||
            !fFunctions.fGetFramebufferAttachmentParameteriv ||
            !fFunctions.fGetRenderbufferParameteriv ||
            !fFunctions.fRenderbufferStorage) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(3,0)) ||
          fExtensions.has("GL_ARB_framebuffer_object") ||
          fExtensions.has("GL_EXT_framebuffer_blit"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0)) ||
          fExtensions.has("GL_CHROMIUM_framebuffer_multisample") ||
          fExtensions.has("GL_ANGLE_framebuffer_blit"))) ||
       (GR_IS_GR_WEBGL(fStandard) && (
          (glVer >= GR_GL_VER(2,0))))) {
        if (!fFunctions.fBlitFramebuffer) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(3,0)) ||
          fExtensions.has("GL_ARB_framebuffer_object") ||
          fExtensions.has("GL_EXT_framebuffer_multisample"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0)) ||
          fExtensions.has("GL_CHROMIUM_framebuffer_multisample") ||
          fExtensions.has("GL_ANGLE_framebuffer_multisample"))) ||
       (GR_IS_GR_WEBGL(fStandard) && (
          (glVer >= GR_GL_VER(2,0))))) {
        if (!fFunctions.fRenderbufferStorageMultisample) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_CHROMIUM_map_sub")))) {
        if (!fFunctions.fMapBufferSubData ||
            !fFunctions.fMapTexSubImage2D ||
            !fFunctions.fUnmapBufferSubData ||
            !fFunctions.fUnmapTexSubImage2D) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_EXT_multisampled_render_to_texture") ||
          fExtensions.has("GL_IMG_multisampled_render_to_texture")))) {
        if (!fFunctions.fFramebufferTexture2DMultisample) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_EXT_multisampled_render_to_texture")))) {
        if (!fFunctions.fRenderbufferStorageMultisampleES2EXT) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_IMG_multisampled_render_to_texture")))) {
        if (!fFunctions.fRenderbufferStorageMultisampleES2EXT) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_APPLE_framebuffer_multisample")))) {
        if (!fFunctions.fResolveMultisampleFramebuffer ||
            !fFunctions.fRenderbufferStorageMultisampleES2APPLE) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if (GR_IS_GR_GL(fStandard) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_OES_mapbuffer")))) {
        if (!fFunctions.fMapBuffer) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if (GR_IS_GR_GL(fStandard) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0)) ||
          fExtensions.has("GL_OES_mapbuffer")))) {
        if (!fFunctions.fUnmapBuffer) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(3,0)) ||
          fExtensions.has("GL_ARB_map_buffer_range"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0)) ||
          fExtensions.has("GL_EXT_map_buffer_range")))) {
        if (!fFunctions.fFlushMappedBufferRange ||
            !fFunctions.fMapBufferRange) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          fExtensions.has("GL_EXT_debug_marker"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_EXT_debug_marker")))) {
        if (!fFunctions.fInsertEventMarker ||
            !fFunctions.fPopGroupMarker ||
            !fFunctions.fPushGroupMarker) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(4,3)) ||
          fExtensions.has("GL_ARB_program_interface_query"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,1))))) {
        if (!fFunctions.fGetProgramResourceLocation) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          fExtensions.has("GL_NV_path_rendering"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_CHROMIUM_path_rendering") ||
          fExtensions.has("GL_NV_path_rendering")))) {
        if (!fFunctions.fMatrixLoadIdentity ||
            !fFunctions.fMatrixLoadf) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          fExtensions.has("GL_NV_path_rendering"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_CHROMIUM_path_rendering") ||
          fExtensions.has("GL_NV_path_rendering")))) {
        if (!fFunctions.fCoverFillPath ||
            !fFunctions.fCoverFillPathInstanced ||
            !fFunctions.fCoverStrokePath ||
            !fFunctions.fCoverStrokePathInstanced ||
            !fFunctions.fDeletePaths ||
            !fFunctions.fGenPaths ||
            !fFunctions.fIsPath ||
            !fFunctions.fPathCommands ||
            !fFunctions.fPathParameterf ||
            !fFunctions.fPathParameteri ||
            !fFunctions.fPathStencilFunc ||
            !fFunctions.fStencilFillPath ||
            !fFunctions.fStencilFillPathInstanced ||
            !fFunctions.fStencilStrokePath ||
            !fFunctions.fStencilStrokePathInstanced) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_CHROMIUM_path_rendering")))) {
        if (!fFunctions.fBindFragmentInputLocation) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          fExtensions.has("GL_NV_framebuffer_mixed_samples"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_CHROMIUM_framebuffer_mixed_samples") ||
          fExtensions.has("GL_NV_framebuffer_mixed_samples")))) {
        if (!fFunctions.fCoverageModulation) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(4,3)) ||
          fExtensions.has("GL_KHR_debug"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_KHR_debug")))) {
        if (!fFunctions.fDebugMessageCallback ||
            !fFunctions.fDebugMessageControl ||
            !fFunctions.fDebugMessageInsert ||
            !fFunctions.fGetDebugMessageLog ||
            !fFunctions.fObjectLabel ||
            !fFunctions.fPopDebugGroup ||
            !fFunctions.fPushDebugGroup) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_CHROMIUM_bind_uniform_location")))) {
        if (!fFunctions.fBindUniformLocation) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          fExtensions.has("GL_EXT_window_rectangles"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_EXT_window_rectangles")))) {
        if (!fFunctions.fWindowRectangles) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(3,2)) ||
          fExtensions.has("GL_ARB_sync"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0)) ||
          fExtensions.has("GL_APPLE_sync"))) ||
       (GR_IS_GR_WEBGL(fStandard) && (
          (glVer >= GR_GL_VER(2,0))))) {
        if (!fFunctions.fClientWaitSync ||
            !fFunctions.fDeleteSync ||
            !fFunctions.fFenceSync ||
            !fFunctions.fIsSync ||
            !fFunctions.fWaitSync) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(4,2)) ||
          fExtensions.has("GL_ARB_internalformat_query"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0))))) {
        if (!fFunctions.fGetInternalformativ) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(4,1)))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0)) ||
          fExtensions.has("GL_OES_get_program_binary")))) {
        if (!fFunctions.fGetProgramBinary ||
            !fFunctions.fProgramBinary) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(4,1)))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0))))) {
        if (!fFunctions.fProgramParameteri) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(3,2)) ||
          fExtensions.has("GL_ARB_sampler_objects"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0)))) ||
       (GR_IS_GR_WEBGL(fStandard) && (
          (glVer >= GR_GL_VER(2,0))))) {
        if (!fFunctions.fBindSampler ||
            !fFunctions.fDeleteSamplers ||
            !fFunctions.fGenSamplers ||
            !fFunctions.fSamplerParameteri ||
            !fFunctions.fSamplerParameteriv) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if (GR_IS_GR_GL(fStandard)) {
        if (!fFunctions.fGetQueryObjectiv) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if (GR_IS_GR_GL(fStandard) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0)) ||
          fExtensions.has("GL_EXT_occlusion_query_boolean")))) {
#if GR_TEST_UTILS
        if (!fFunctions.fBeginQuery ||
            !fFunctions.fDeleteQueries ||
            !fFunctions.fEndQuery ||
            !fFunctions.fGenQueries ||
            !fFunctions.fGetQueryObjectuiv ||
            !fFunctions.fGetQueryiv) {
            RETURN_FALSE_INTERFACE;
        }
#endif
        // all functions were marked optional or test_only
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(3,3)) ||
          fExtensions.has("GL_ARB_timer_query") ||
          fExtensions.has("GL_EXT_timer_query")))) {
        if (!fFunctions.fGetQueryObjecti64v ||
            !fFunctions.fGetQueryObjectui64v) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(3,3)) ||
          fExtensions.has("GL_ARB_timer_query")))) {
        if (!fFunctions.fQueryCounter) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(4,3)) ||
          fExtensions.has("GL_ARB_invalidate_subdata")))) {
        if (!fFunctions.fInvalidateBufferData ||
            !fFunctions.fInvalidateBufferSubData ||
            !fFunctions.fInvalidateTexImage ||
            !fFunctions.fInvalidateTexSubImage) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(4,3)) ||
          fExtensions.has("GL_ARB_invalidate_subdata"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          (glVer >= GR_GL_VER(3,0)))) ||
       (GR_IS_GR_WEBGL(fStandard) && (
          (glVer >= GR_GL_VER(2,0))))) {
        if (!fFunctions.fInvalidateFramebuffer ||
            !fFunctions.fInvalidateSubFramebuffer) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          (glVer >= GR_GL_VER(4,3)) ||
          fExtensions.has("GL_ARB_ES2_compatibility"))) ||
       GR_IS_GR_GL_ES(fStandard) ||
       GR_IS_GR_WEBGL(fStandard)) {
        if (!fFunctions.fGetShaderPrecisionFormat) {
            RETURN_FALSE_INTERFACE;
        }
    }

    if ((GR_IS_GR_GL(fStandard) && (
          fExtensions.has("GL_NV_fence"))) ||
       (GR_IS_GR_GL_ES(fStandard) && (
          fExtensions.has("GL_NV_fence")))) {
        if (!fFunctions.fDeleteFences ||
            !fFunctions.fFinishFence ||
            !fFunctions.fGenFences ||
            !fFunctions.fSetFence ||
            !fFunctions.fTestFence) {
            RETURN_FALSE_INTERFACE;
        }
    }


    // End autogenerated content
    return true;
}

#if GR_TEST_UTILS

void GrGLInterface::abandon() const {
    const_cast<GrGLInterface*>(this)->fFunctions = GrGLInterface::Functions();
}

#endif // GR_TEST_UTILS
