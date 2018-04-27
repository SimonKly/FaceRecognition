#ifndef MISCELLANEOUS_H
#define MISCELLANEOUS_H
//namespace UTILS {


#define APPID     "7xNBCHMY1MpxRY2hqSWeEcz5whkhBCQqGSVFAkxSqHcd"
#define SDKKEY_AE    "DQz7rMe8wNiXvzCmku1avGusNknYWHJy3jqT1m2Tnwvq"
#define SDKKEY_FD    "DQz7rMe8wNiXvzCmku1avGu8QMDYDMoU5xpvSEhp4AH2"
#define SDKKEY_FR    "DQz7rMe8wNiXvzCmku1avGuVtZ12AFha9qr2et3cbTRx"
#define SDKKEY_FT    "DQz7rMe8wNiXvzCmku1avGuzYA3gM7hnLSWmdMic2hGJ"
#define SDKKEY_GE    "DQz7rMe8wNiXvzCmku1avGu1EwxKNTtBZyjU2M5E8Lpn"


#define INPUT1_IMAGE_FORMAT  ASVL_PAF_I420
#define INPUT1_IMAGE_PATH    "your_input1_image.yuv"
#define INPUT1_IMAGE_WIDTH   (640)
#define INPUT1_IMAGE_HEIGHT  (480)

#define INPUT2_IMAGE_FORMAT  ASVL_PAF_I420
#define INPUT2_IMAGE_PATH    "your_input2_image.yuv"
#define INPUT2_IMAGE_WIDTH   (640)
#define INPUT2_IMAGE_HEIGHT  (880)

//#define WORKBUF_SIZE        (40*1024*1024)
const unsigned int WORKBUF_SIZE = 40*1024*1024;

#include "amcomdef.h"
#include <QString>
#include <QByteArray>
namespace MISCELLANEOUS {


MPChar CChar2Char(MPCChar cpStr);



}
#endif // UTILS_H
