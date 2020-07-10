/*
 * Copyright 2019 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrRGBToHSLFilterEffect.fp; do not modify.
 **************************************************************************************************/
#ifndef GrRGBToHSLFilterEffect_DEFINED
#define GrRGBToHSLFilterEffect_DEFINED

#include "include/core/SkM44.h"
#include "include/core/SkTypes.h"

#include "src/gpu/GrFragmentProcessor.h"

class GrRGBToHSLFilterEffect : public GrFragmentProcessor {
public:
#include "include/private/SkColorData.h"

    SkPMColor4f constantOutputForConstantInput(const SkPMColor4f& inColor) const override {
        SkPMColor4f c = this->numChildProcessors()
                                ? ConstantOutputForConstantInput(this->childProcessor(0), inColor)
                                : inColor;
        const auto p = (c.fG < c.fB) ? SkPMColor4f{c.fB, c.fG, -1, 2 / 3.f}
                                     : SkPMColor4f{c.fG, c.fB, 0, -1 / 3.f},
                   q = (c.fR < p[0]) ? SkPMColor4f{p[0], c.fR, p[1], p[3]}
                                     : SkPMColor4f{c.fR, p[0], p[1], p[2]};

        const auto eps = 0.0001f,  // matching SkSL/ColorMatrix half4 epsilon
                pmV = q[0], pmC = pmV - std::min(q[1], q[2]), pmL = pmV - pmC * 0.5f,
                   H = std::abs(q[3] + (q[1] - q[2]) / (pmC * 6 + eps)),
                   S = pmC / (c.fA + eps - std::abs(pmL * 2 - c.fA)), L = pmL / (c.fA + eps);

        return {H, S, L, c.fA};
    }
    static std::unique_ptr<GrFragmentProcessor> Make(std::unique_ptr<GrFragmentProcessor> inputFP) {
        return std::unique_ptr<GrFragmentProcessor>(new GrRGBToHSLFilterEffect(std::move(inputFP)));
    }
    GrRGBToHSLFilterEffect(const GrRGBToHSLFilterEffect& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "RGBToHSLFilterEffect"; }
    int inputFP_index = -1;

private:
    GrRGBToHSLFilterEffect(std::unique_ptr<GrFragmentProcessor> inputFP)
            : INHERITED(kGrRGBToHSLFilterEffect_ClassID,
                        (OptimizationFlags)(inputFP ? ProcessorOptimizationFlags(inputFP.get())
                                                    : kAll_OptimizationFlags) &
                                (kConstantOutputForConstantInput_OptimizationFlag |
                                 kPreservesOpaqueInput_OptimizationFlag)) {
        inputFP_index = this->registerChild(std::move(inputFP), SkSL::SampleUsage::PassThrough());
    }
    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    typedef GrFragmentProcessor INHERITED;
};
#endif
