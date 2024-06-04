
#ifndef VTKUTILS_GLOBAL_H
#define VTKUTILS_GLOBAL_H


#include <QtCore/qglobal.h>


#if defined(VTKUTILS_LIBRARY)
#  define VTKUTILS_EXPORT Q_DECL_EXPORT
#else
#  define VTKUTILS_EXPORT Q_DECL_IMPORT
#endif

#include "vtkAutoInit.h"
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType)


#endif // VTKUTILS_GLOBAL_H
