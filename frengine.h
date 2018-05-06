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

    /*
	 * @brief: 对Face Recognition引擎进行初始化操作
	 * @return value:初始化成功返回MOK，否则返回error code，具体错误参考merror.h
	 */
    MRESULT init();

	/*
	 * @brief: 提取人脸特征值
	 * @param pInputImg [in]:输入图片结构指针
	 * @param pFaceRes [in]:图片中人脸信息
	 * @param pModel [out]:输出人脸特征值
	 * @return value:提取成功返回MOK，否则返回error code，具体错误参考merror.h
	 */
    MRESULT extractFRFeature(LPASVLOFFSCREEN pInputImg,
                             LPAFR_FSDK_FACEINPUT pFaceRes,
                             LPAFR_FSDK_FACEMODEL pModel);

	/*
	 * @brief: 人脸匹配
	 * @param reffeatures [in]:已有的特征值
	 * @param probefeatures [in]:被比较特征值
	 * @param pScore [out]:输出相似度
	 * @return value:函数运行成功返回MOK，否则返回error code，具体错误参考merror.h
	 */
    MRESULT faceMatching(AFR_FSDK_FACEMODEL *reffeatures,
                         AFR_FSDK_FACEMODEL *probefeatures,
                         MFloat *pScore);
	/*
	* @brief:销毁引擎
	* @return value:初始化成功返回MOK，否则返回error code，具体错误参考merror.h
	*/
    MRESULT uninit();

private:
    MHandle m_FREngine;
    MByte *m_pWorkMem;

};

#endif // FRENGINE_H
