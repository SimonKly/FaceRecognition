#include "fdengine.h"
#include <new>
#include <cassert>

FDEngine::FDEngine()
{
    this->m_pMem = nullptr;
    this->m_pEngine = nullptr;
}

FDEngine::~FDEngine()
{
    //this->uninit();
}

/*
 * @brief:初始化引擎
 * @return value:初始化成功返回MOK，否则返回error code，具体错误参考merror.h
 */
MRESULT FDEngine::init()
{
    try
    {
        this->m_pMem = new MByte[WORKBUF_SIZE];
    }
    catch(std::bad_alloc &excp)
    {
        assert(excp.what());
    }

    MRESULT ret = AFD_FSDK_InitialFaceEngine(APPID, SDKKEY, this->m_pMem,
                                             WORKBUF_SIZE, this->m_pEngine,
                                             AFD_FSDK_OPF_0_ONLY, 16, 50);

    return ret;
}

/*
 * @brief:获取人脸位置
 * @param [in]:pImgData
 * @param [out]:pFaceRes
 * @return value:初始化成功返回MOK，否则返回error code，具体错误参考merror.h
 */
MRESULT FDEngine::faceDetection(LPASVLOFFSCREEN pImgData, LPAFD_FSDK_FACERES *pFaceRes)
{
    MRESULT ret = AFD_FSDK_StillImageFaceDetection(this->m_pEngine, pImgData, pFaceRes);
    return ret;
}

/*
 * @brief:销毁引擎
 * @return value:初始化成功返回MOK，否则返回error code，具体错误参考merror.h
 */
MRESULT FDEngine::uninit()
{
    if (this->m_pEngine != nullptr)
    {
        MRESULT ret = AFD_FSDK_UninitialFaceEngine(this->m_pEngine);
        return ret;
    }
    if (this->m_pMem != nullptr)
    {
        delete []this->m_pMem;
    }
    this->m_pMem = nullptr;
    this->m_pEngine = nullptr;

    return MOK;
}
