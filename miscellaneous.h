#ifndef MISCELLANEOUS_H
#define MISCELLANEOUS_H

const unsigned int WORKBUF_SIZE = 40*1024*1024;

#include "amcomdef.h"
#include <QString>
#include <QByteArray>
#include <QImage>

namespace MISCELLANEOUS {

/* 虹软的认证串 */
class Authenticate
{
public:
    static QString APPID;
    static QString SDKKEY_AE;
    static  QString SDKKEY_FD;
    static QString SDKKEY_FR;
    static QString SDKKEY_FT;
    static QString SDKKEY_GE;
};

// 为了程序少一些平台相关性，剔出bmp的信息头定义
typedef struct tagBITMAPINFOHEADER {
	unsigned long      biSize;
	long       biWidth;
	long       biHeight;
	unsigned short       biPlanes;
	unsigned short       biBitCount;
	unsigned long      biCompression;
	unsigned long      biSizeImage;
	long       biXPelsPerMeter;
	long       biYPelsPerMeter;
	unsigned long      biClrUsed;
	unsigned long      biClrImportant;
} BITMAPINFOHEADER, *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;

/*
 * @brief:将const char * 转换为 char *
 * @param cpStr [in]:const char *格式的字符串
 * @return value: 转换之后的char *字符串
 */
MPChar CChar2Char(MPCChar cpStr);

/*
 * @brief:读取bmp格式的 
 * @param filePath [in]:bmp文件路径
 * @param imgData [out]:存入图片的信息
 * @param pWidth [out]:图片width
 * @param pHeight [out]:图片height
 * @return value: 图片位宽正确返回true，否则false
 */
bool readBmp(QString &filePath, unsigned char **imgData, int *pWidth, int *pHeight);

}
#endif // UTILS_H
