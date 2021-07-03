#pragma once

#include <qglobal.h>

#if defined(SDK_LIBRARY)
#  define SDK_EXPORT Q_DECL_EXPORT
#else
#  define SDK_EXPORT Q_DECL_IMPORT
#endif
