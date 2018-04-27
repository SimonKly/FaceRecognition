#ifndef FTENGINE_H
#define FTENGINE_H

#include "amcomdef.h"
#include "arcsoft_fsdk_face_tracking.h"
#include "merror.h"

#include "asvloffscreen.h"

class FTEngine
{
public:
    FTEngine();
    ~FTEngine();

    // 初始化脸部检测引擎
    MRESULT init();

    // 根据输入的图像检测人脸，一般用于视频检测，多帧方式
    // param: pImgData [in] 待检测图像信息
    // param: pFaceRes [out] 人脸检测结果
    // return value: 成功返回MOK, 否则返回失败code
    MRESULT detectFace(LPASVLOFFSCREEN pImgData, LPAFT_FSDK_FACERES *pFaceRes);

    // 销毁脸部检测引擎
    MRESULT uninit();

private:
    MHandle *m_pEngine;
    MByte *m_pMem;


};
#endif // FTENGINE_H
