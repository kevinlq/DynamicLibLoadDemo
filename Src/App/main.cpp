#include <QCoreApplication>
#include <QLibrary>
#include <QDebug>
#include <QJsonDocument>

#include "Libs/SDKStruct.h"

typedef int (* pRunFunctionFun)(const char *, const DS_Request &, DS_Request&);

#define GET_SDK_FUNC(type, func, symbol)  GET_FUNC(sdk, type, func, symbol);

#define GET_FUNC(sdk, type, func, symbol) \
    type func = getFunction<type>(&sdk, symbol); \
    if (func == nullptr) \
{ \
    qDebug()<<"fun is null: "<< symbol; \
    return 0; \
}

template <typename T>
T getFunction(QLibrary *lib, const char *func)
{
    T f = (T)lib->resolve(func);
    if (f == nullptr)
    {
        return nullptr;
    }
    return f;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QString strSDKName = QString("%1%2%3").arg(LIB_DIR_PATH).arg(LIB_NAME).arg(FILE_DLL_EXT);

    QLibrary library(strSDKName);

    bool bLoad = library.load();

    qDebug() << "#LIB_DIR_PATH " << strSDKName
             << "bLoad:" << bLoad << library.isLoaded();

    if (!bLoad)
    {
        return 0;
    }

    QVariantMap mapParam;
    mapParam.insert("nValue1", 1);
    mapParam.insert("nValue2", 2);

    DS_Request request, response;
    request.m_strData = QString(QJsonDocument::fromVariant(mapParam).toJson());

    // 调用方法1
    GET_FUNC(library, pRunFunctionFun, runFun, "runFunction");

    int nRet = runFun("addNum", request, response);

    qDebug() << "add Resut:" << nRet << response.m_strData;

    //return 0;
    // 调用方法2

    pRunFunctionFun pFun = (pRunFunctionFun) library.resolve("runFunction");

    if ( pFun)
    {
        int nRet = pFun("addNum", request, response);

        qDebug() << "add Resut:" << nRet << response.m_strData;
    }


    return app.exec();
}
