#ifndef THIRDPARTY_GLOBAL_H
#define THIRDPARTY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(THIRDPARTY_LIBRARY)
#  define THIRDPARTY_EXPORT Q_DECL_EXPORT
#else
#  define THIRDPARTY_EXPORT Q_DECL_IMPORT
#endif

#endif // THIRDPARTY_GLOBAL_H