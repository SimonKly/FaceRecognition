#ifndef FDENGINE_H
#define FDENGINE_H

#include "amcomdef.h"
#include "arcsoft_fsdk_face_detection.h"
#include "merror.h"
#include "asvloffscreen.h"

/*
 * @brief:获取静态图片中人脸的位置
 */
class FDEngine
{
public:
    FDEngine();
    ~FDEngine();

    /*
     * @brief:初始化引擎
	 * @param nScale [in]:人脸相对于相片的缩放比例，default 16
	 * @param nMaxFaceNum [in]:能够识别人脸的数目，default 50
     * @return value:初始化成功返回MOK，否则返回error code，具体错误参考merror.h
     */
    MRESULT init(int nScale = 16, int nMaxFaceNum = 50);

    /*
     * @brief:获取人脸位置
     * @param [in]:pImgData
     * @param [out]:pFaceRes
     * @return value:初始化成功返回MOK，否则返回error code，具体错误参考merror.h
     */
    MRESULT faceDetection(LPASVLOFFSCREEN pImgData, LPAFD_FSDK_FACERES *pFaceRes);

    /*
     * @brief:销毁引擎
     * @return value:初始化成功返回MOK，否则返回error code，具体错误参考merror.h
     */
    MRESULT uninit();

private:

    MByte *m_pMem;
    MHandle m_pEngine;

};

#endif // FDENGINE_H
