#include "frengine.h"
#include "utils.h"

FREngine::FREngine()
{
    this->m_FREngine = nullptr;
    this->m_pWorkMem = nullptr;
}

FREngine::~FREngine()
{
    uninit();
}

MRESULT FREngine::init()
{
    MByte *m_pWorkMem = new MByte(WORKBUF_SIZE);
    int ret = AFR_FSDK_InitialEngine(APPID, SDKKEY, m_pWorkMem, WORKBUF_SIZE, &m_FREngine);
    return ret;
}

MRESULT FREngine::extractFRFeature(LPASVLOFFSCREEN *pInputImg,
                                   LPAFR_FSDK_FACEINPUT *pFaceRes,
                                   LPAFR_FSDK_FACEMODEL *pModel)
{
    int ret = AFR_FSDK_ExtractFRFeature(this->m_FREngine, pInputImg, pFaceRes, pModel);
    return ret;
}

MRESULT FREngine::faceMatching(LPAFR_FSDK_FACEMODEL *reffeatures,
                               LPAFR_FSDK_FACEMODEL *probefeatures,
                               MFloat *pScore)
{
    int ret = AFR_FSDK_FacePairMatching(this->m_FREngine, reffeatures, probefeatures, pScore);
    return ret;
}

MRESULT FREngine::uninit()
{
    delete []this->m_pWorkMem;
    int ret = AFR_FSDK_UninitialEngine(this->m_FREngine);
    return ret;
}
