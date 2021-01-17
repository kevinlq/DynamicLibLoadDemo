#ifndef SDKCORE_H
#define SDKCORE_H

#include <QObject>

#include "SDKCore_global.h"
#include "SDKStruct.h"

extern "C" SDK_EXPORT int runFunction(const char * funName, const DS_Request &request, DS_Request& response);

#endif // SDKCORE_H
