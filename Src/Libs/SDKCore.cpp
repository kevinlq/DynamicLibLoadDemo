#include "SDKCore.h"

#include "SDKCoreImpl.h"


int runFunction(const char *funName, const DS_Request &request, DS_Request &response)
{
    Internal::SDKCoreImpl m_pCoreImpl;

    int nRet = -1;
    QMetaObject::invokeMethod(&m_pCoreImpl, funName,
                              Qt::DirectConnection,
                              Q_RETURN_ARG(int, nRet),
                              Q_ARG(DS_Request, request),
                              Q_ARG(DS_Request&,response));

    return nRet;
}
