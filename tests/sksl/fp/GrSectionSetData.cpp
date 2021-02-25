

/**************************************************************************************************
 *** This file was autogenerated from GrSectionSetData.fp; do not modify.
 **************************************************************************************************/
#include "GrSectionSetData.h"

#include "src/core/SkUtils.h"
#include "src/gpu/GrTexture.h"
#include "src/gpu/glsl/GrGLSLFragmentProcessor.h"
#include "src/gpu/glsl/GrGLSLFragmentShaderBuilder.h"
#include "src/gpu/glsl/GrGLSLProgramBuilder.h"
#include "src/sksl/SkSLCPP.h"
#include "src/sksl/SkSLUtil.h"
class GrGLSLSectionSetData : public GrGLSLFragmentProcessor {
public:
    GrGLSLSectionSetData() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrSectionSetData& _outer = args.fFp.cast<GrSectionSetData>();
        (void) _outer;
        auto provided = _outer.provided;
        (void) provided;
        calculatedVar = args.fUniformHandler->addUniform(&_outer, kFragment_GrShaderFlag, kHalf_GrSLType, "calculated");
        fragBuilder->codeAppendf(
R"SkSL(return half4(1.0);
)SkSL"
);
    }
private:
    void onSetData(const GrGLSLProgramDataManager& varName, const GrFragmentProcessor& _proc) override {
        UniformHandle& calculated = calculatedVar;
        (void) calculated;
        const GrSectionSetData& _outer = _proc.cast<GrSectionSetData>();
        auto provided = _outer.provided;
        (void) provided;
 varName.set1f(calculated, provided * 2);     }
    UniformHandle calculatedVar;
};
std::unique_ptr<GrGLSLFragmentProcessor> GrSectionSetData::onMakeProgramImpl() const {
    return std::make_unique<GrGLSLSectionSetData>();
}
void GrSectionSetData::onGetGLSLProcessorKey(const GrShaderCaps& caps, GrProcessorKeyBuilder* b) const {
    b->add32(sk_bit_cast<uint32_t>(provided));
}
bool GrSectionSetData::onIsEqual(const GrFragmentProcessor& other) const {
    const GrSectionSetData& that = other.cast<GrSectionSetData>();
    (void) that;
    if (provided != that.provided) return false;
    return true;
}
GrSectionSetData::GrSectionSetData(const GrSectionSetData& src)
: INHERITED(kGrSectionSetData_ClassID, src.optimizationFlags())
, provided(src.provided) {
        this->cloneAndRegisterAllChildProcessors(src);
}
std::unique_ptr<GrFragmentProcessor> GrSectionSetData::clone() const {
    return std::make_unique<GrSectionSetData>(*this);
}
#if GR_TEST_UTILS
SkString GrSectionSetData::onDumpInfo() const {
    return SkStringPrintf("(provided=%f)", provided);
}
#endif
