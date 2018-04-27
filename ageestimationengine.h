#ifndef AGEESTIMATION_H
#define AGEESTIMATION_H

#include "arcsoft_fsdk_age_estimation.h"
#include "miscellaneous.h"
#include "amcomdef.h"
#include "merror.h"
#include "asvloffscreen.h"

class AgeEstimationEngine
{
public:
    AgeEstimationEngine();
    ~AgeEstimationEngine();

    /*
     * @brief:初始化预估年龄引擎
     */
    MRESULT init();

    /*
     * @brief:获取图片中人脸年龄
     * @param pImg [in]:输入图像数据
     * @param pFaceRes [in]:输入人脸数据
     * @param pAgeRes [out]:输出年龄
     *
     */
    MRESULT getAgeEstimageStaticImg(LPASVLOFFSCREEN pImg,
                                    LPASAE_FSDK_AGEFACEINPUT pFaceRes,
                                    LPASAE_FSDK_AGERESULT pAgeRes);

    /*
     * @brief:获取动态视频中人脸年龄
     * @param pImg [in]:输入图像数据
     * @param pFaceRes [in]:输入人脸数据
     * @param pAgeRes [out]:输出年龄
     */
    MRESULT getAgeEstimageStaticVideo(LPASVLOFFSCREEN pImg,
                                      LPASAE_FSDK_AGEFACEINPUT pFaceRes,
                                      LPASAE_FSDK_AGERESULT pAgeRes);

    /*
     * @brief:销毁引擎，释放资源
     */
    MRESULT uninit();

private:
    MByte *m_pMem;
    MHandle *m_pEngine;


};



#endif // AGEESTIMATION_H
