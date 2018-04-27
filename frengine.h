#ifndef FRENGINE_H
#define FRENGINE_H

#include "amcomdef.h"
#include "asvloffscreen.h"
#include "arcsoft_fsdk_face_recognition.h"

/*
 * @brief: 对虹软的SDK进行封装
 */
class FREngine
{
public:

    /*
     * @brief: 对成员变量清0处理
     */
    FREngine();

    ~FREngine();

    //
    MRESULT init();

    MRESULT extractFRFeature(LPASVLOFFSCREEN pInputImg,
                             LPAFR_FSDK_FACEINPUT pFaceRes,
                             LPAFR_FSDK_FACEMODEL pModel);

    MRESULT faceMatching(AFR_FSDK_FACEMODEL *reffeatures,
                         AFR_FSDK_FACEMODEL *probefeatures,
                         MFloat *pScore);

    MRESULT uninit();

private:
    MHandle m_FREngine;
    MByte *m_pWorkMem;

};

#endif // FRENGINE_H
