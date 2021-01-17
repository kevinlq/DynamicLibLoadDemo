# DynamicLibLoadDemo
QLibrary 加载动态库详细用法，封装调用方法，使用简单快速、方法使用 Qt 反射更快捷


核心代码

``` C++
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
```

使用

``` C++
    QString strSDKName = QString("%1%2%3").arg(LIB_DIR_PATH).arg(LIB_NAME).arg(FILE_DLL_EXT);

    QLibrary library(strSDKName);

    bool bLoad = library.load();
	
	    // 调用方法1
    GET_FUNC(library, pRunFunctionFun, runFun, "runFunction");

    int nRet = runFun("addNum", request, response);

    qDebug() << "add Resut:" << nRet << response.m_strData;
	
```

反射调用

``` C++
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
```