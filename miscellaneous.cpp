#include "miscellaneous.h"
#include <QDebug>
//#include <Windows.h>
#include <QFile>

QString MISCELLANEOUS::Authenticate::APPID("7xNBCHMY1MpxRY2hqSWeEcz5whkhBCQqGSVFAkxSqHcd");

QString MISCELLANEOUS::Authenticate::SDKKEY_AE("DQz7rMe8wNiXvzCmku1avGusNknYWHJy3jqT1m2Tnwvq");
QString MISCELLANEOUS::Authenticate::SDKKEY_FD("DQz7rMe8wNiXvzCmku1avGu8QMDYDMoU5xpvSEhp4AH2");
QString MISCELLANEOUS::Authenticate::SDKKEY_FR("DQz7rMe8wNiXvzCmku1avGuVtZ12AFha9qr2et3cbTRx");
QString MISCELLANEOUS::Authenticate::SDKKEY_FT("DQz7rMe8wNiXvzCmku1avGu1EwxKNTtBZyjU2M5E8Lpn");
QString MISCELLANEOUS::Authenticate::SDKKEY_GE("DQz7rMe8wNiXvzCmku1avGuzYA3gM7hnLSWmdMic2hGJ");

MPChar MISCELLANEOUS::CChar2Char(MPCChar cpStr)
{
    QString str(cpStr);
    QByteArray byteArray = str.toLatin1();
    MPChar res = byteArray.data();
    return res;
}

bool MISCELLANEOUS::readBmp(QString &filePath, unsigned char **imageData, int *pWidth, int *pHeight)
{
    QFile fileImage(filePath);
    fileImage.open(QIODevice::ReadWrite);
    QByteArray imageByteArray = fileImage.readAll();
    fileImage.close();
    const char* pBuffer = imageByteArray.data();
    MISCELLANEOUS::BITMAPINFOHEADER head;
    memcpy(&head, pBuffer + 14, sizeof(BITMAPINFOHEADER));
    *pWidth = head.biWidth;
    *pHeight = head.biHeight;
    int biBitCount = head.biBitCount;

    if (24 == biBitCount)
    {
        int lineByte = ((*pWidth) * biBitCount / 8 + 3) / 4 * 4;
        *imageData = (uint8_t *)malloc(lineByte * (*pHeight));
        for (int i = 0; i < *pHeight; i++)
        {
            memcpy(*imageData + i * (*pWidth) * 3, pBuffer + (*pHeight - 1 - i) * lineByte + 54, (*pWidth) * 3);
        }
    }
    else if (32 == biBitCount)
    {
        *imageData = (uint8_t *)malloc((*pWidth) * (*pHeight) * 3);
        for (int i = 0; i < *pHeight; i++)
        {
            for (int j = 0; j < *pWidth; j++)
            {
                memcpy((*imageData) + i * (*pWidth) * 3 + j * 3, pBuffer + (((*pHeight) - 1) - i) * (*pWidth) * 4 + j * 4 + 54, 3);
            }
        }
    }
    else
    {
        return false;
    }
    return true;


}
