#include "frengine.h"
#include "miscellaneous.h"

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
    this->m_pWorkMem = new MByte[WORKBUF_SIZE];
    int ret = AFR_FSDK_InitialEngine(MISCELLANEOUS::Authenticate::APPID.toLatin1().data(), 
		MISCELLANEOUS::Authenticate::SDKKEY_FD.toLatin1().data(), 
		m_pWorkMem, WORKBUF_SIZE, &m_FREngine);
    return ret;
}

MRESULT FREngine::extractFRFeature(LPASVLOFFSCREEN pInputImg,
                                   LPAFR_FSDK_FACEINPUT pFaceRes,
                                   LPAFR_FSDK_FACEMODEL pModel)
{
    int ret = AFR_FSDK_ExtractFRFeature(this->m_FREngine, pInputImg, pFaceRes, pModel);
    return ret;
}

MRESULT FREngine::faceMatching(AFR_FSDK_FACEMODEL *reffeatures,
                               AFR_FSDK_FACEMODEL *probefeatures,
                               MFloat *pScore)
{
    int ret = AFR_FSDK_FacePairMatching(this->m_FREngine, reffeatures, probefeatures, pScore);
    return ret;
}

MRESULT FREngine::uninit()
{
	if (this->m_pWorkMem != nullptr)
		delete[]this->m_pWorkMem;
    int ret = AFR_FSDK_UninitialEngine(this->m_FREngine);
    return ret;
}
