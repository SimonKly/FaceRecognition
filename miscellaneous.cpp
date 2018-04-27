#include "miscellaneous.h"

MPChar MISCELLANEOUS::CChar2Char(MPCChar cpStr)
{
    QString str(cpStr);
    QByteArray byteArray = str.toLatin1();
    MPChar res = byteArray.data();
    return res;
}
