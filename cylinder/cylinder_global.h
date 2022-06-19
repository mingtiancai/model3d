#ifndef CYLINDER_GLOBAL_H
#define CYLINDER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CYLINDER_LIBRARY)
#  define CYLINDER_EXPORT Q_DECL_EXPORT
#else
#  define CYLINDER_EXPORT Q_DECL_IMPORT
#endif

#endif // CYLINDER_GLOBAL_H
