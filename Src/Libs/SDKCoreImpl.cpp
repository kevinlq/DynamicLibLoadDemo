#include "SDKCoreImpl.h"

#include <QJsonDocument>
#include <QVariantMap>

//using namespace Core;

namespace Internal {

SDKCoreImpl::SDKCoreImpl()
{
}

int SDKCoreImpl::addNum(const DS_Request &request, DS_Request &response)
{
    QVariantMap map = QJsonDocument::fromJson(request.m_strData.toLatin1()).toVariant().toMap();

    int nValue1 = map.value("nValue1").toInt();
    int nValue2 = map.value("nValue2").toInt();

    int nResult = nValue1 + nValue2;

    QVariantMap mapResult;
    mapResult.insert("result", nResult);

    QJsonDocument doc = QJsonDocument::fromVariant(mapResult);
    response.m_strData = QString(doc.toJson());

    return SDKCODE_SUCCEED;
}

} // namespace Internal
