#ifndef SDKSTRUCT_H
#define SDKSTRUCT_H

#include <QByteArray>
#include <QString>

enum SDKCode{
    SDKCODE_SUCCEED = 0,
    SDKCODE_FAIL,
    SDKCODE_FUN_NAME_INVALID,
    SDKCODE_UNKNOW_ERROR,
    SDKCODE_SIZE
};

struct DS_Request{
    QString m_strData;
    QByteArray m_baStream;
};

#endif // SDKSTRUCT_H
