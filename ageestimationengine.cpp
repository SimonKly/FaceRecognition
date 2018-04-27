#include "ageestimationengine.h"
#include <cassert>
#include <new>
#include "miscellaneous.h"
/*
 * @brief:初始化年龄识别引擎
 */
MRESULT AgeEstimationEngine::init()
{
    try
    {
        this->m_pMem = new MByte[WORKBUF_SIZE];
    }
    catch(std::bad_alloc &excp)
    {
        assert(excp.what());
    }

    MRESULT res = 0;
    return res;
}

/*
 * @brief:获取图片中人脸年龄
 * @param pImg [in]:输入图像数据
 * @param pFaceRes [in]:输入人脸数据
 * @param pAgeRes [out]:输出年龄
 *
 */
MRESULT AgeEstimationEngine::getAgeEstimageStaticImg(LPASVLOFFSCREEN pImg,
                                LPASAE_FSDK_AGEFACEINPUT pFaceRes,
                                LPASAE_FSDK_AGERESULT pAgeRes)
{
    return 0;
}

/*
 * @brief:获取动态视频中人脸年龄
 * @param pImg [in]:输入图像数据
 * @param pFaceRes [in]:输入人脸数据
 * @param pAgeRes [out]:输出年龄
 */
MRESULT AgeEstimationEngine::getAgeEstimageStaticVideo(LPASVLOFFSCREEN pImg,
                                  LPASAE_FSDK_AGEFACEINPUT pFaceRes,
                                  LPASAE_FSDK_AGERESULT pAgeRes)
{

    return 0;
}

/*
 * @brief:销毁引擎，释放资源
 */
MRESULT AgeEstimationEngine::uninit()
{
    return 0;
}
