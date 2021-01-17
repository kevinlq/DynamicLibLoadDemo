include($$PWD/../../DynamicLibLoadDemo.pri)

QT  +=core

TEMPLATE = app
TARGET = Demo$${FILE_POSTFIX}

INCLUDEPATH +=$$PWD/../

SOURCES += \
    main.cpp
