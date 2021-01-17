include($$PWD/../../DynamicLibLoadDemo.pri)

TEMPLATE = lib
TARGET = $${LIB_NAME}
DESTDIR = $${LIB_DIR_PATH}

DEFINES *= SDK_LIBRARY

HEADERS += \
    SDKCore.h \
    SDKCoreImpl.h \
    SDKStruct.h

SOURCES += \
    SDKCore.cpp \
    SDKCoreImpl.cpp
