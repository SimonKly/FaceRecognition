#include "ftengine.h"
#include <exception>
#include <cassert>
#include <new>
#include "miscellaneous.h"

FTEngine::FTEngine()
{
    this->m_pEngine = nullptr;
    this->m_pMem = nullptr;
}

FTEngine::~FTEngine()
{
    if (this->m_pEngine != nullptr)
    {
        this->uninit();
    }
    if (this->m_pMem != nullptr)
    {
        delete []this->m_pMem;
    }

    this->m_pEngine = nullptr;
    this->m_pMem = nullptr;
}

// 初始化脸部检测引擎
MRESULT FTEngine::init()
{
    try
    {
        this->m_pMem = new MByte[WORKBUF_SIZE];
    }
    catch(std::bad_alloc ex)
    {
        assert(ex.what());
    }
    int ret = AFT_FSDK_InitialFaceEngine(MISCELLANEOUS::CChar2Char(APPID), MISCELLANEOUS::CChar2Char(SDKKEY_FD), this->m_pMem, WORKBUF_SIZE,
                                         this->m_pEngine, AFT_FSDK_OPF_0_ONLY, 16, 50);

    return ret;
}

// 根据输入的图像检测人脸，一般用于视频检测，多帧方式
// param: pImgData [in] 待检测图像信息
// param: pFaceRes [out] 人脸检测结果
// return value: 成功返回MOK, 否则返回失败code
MRESULT FTEngine::detectFace(LPASVLOFFSCREEN pImgData, LPAFT_FSDK_FACERES *pFaceRes)
{
    int ret = AFT_FSDK_FaceFeatureDetect(this->m_pEngine, pImgData, pFaceRes);
    return ret;
}

// 销毁脸部检测引擎
MRESULT FTEngine::uninit()
{
    int ret = AFT_FSDK_UninitialFaceEngine(this->m_pEngine);
    return ret;
}
