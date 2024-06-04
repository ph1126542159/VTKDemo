
#ifndef VTKUTILS_H
#define VTKUTILS_H

///vtk lib
#include "vtkSmartPointer.h"
#include "vtkActor.h"
#include "vtkPolyDataMapper.h"
#include "vtkSphereSource.h"
#include "vtkConeSource.h"

#include <QImage>

#include "vtkutils_global.h"

#ifndef VTK_CREATE
#define VTK_CREATE(TYPE, NAME) vtkSmartPointer<TYPE> NAME = vtkSmartPointer<TYPE>::New()
#endif


class vtkImageData;
class QVTKOpenGLNativeWidget;
class vtkPolyDataAlgorithm;

namespace VtkUtils {
QImage VTKUTILS_EXPORT vtkImageDataToQImage(vtkImageData* imageData);
void VTKUTILS_EXPORT qImageToVtkImage(QImage& img,vtkImageData* imageData);
QImage VTKUTILS_EXPORT vtkWidgetSnapshot(QVTKOpenGLNativeWidget* widget);


template <class T>
void vtkInitOnce(T** obj)
{
    if (*obj == nullptr)
        *obj = T::New();
}

template <class T>
void vtkInitOnce(vtkSmartPointer<T>& obj)
{
    if (!obj)
        obj = vtkSmartPointer<T>::New();
}

template <class T>
void vtkSafeDelete(T* obj)
{
    if (obj)
        obj->Delete();
}

template <class T>
class SourceSetter
{
public:
    void config(T* source)
    {
        Q_UNUSED(source)
        // no impl
    }
};

template <>
class SourceSetter<vtkSphereSource>
{
public:
    void config(vtkSphereSource* )
    {

    }
};

template <>
class SourceSetter<vtkConeSource>
{
public:
    void config(vtkConeSource* )
    {

    }
};

template <class T>
static inline vtkActor* createSourceActor(SourceSetter<T>* setter = nullptr)
{
    vtkActor* actor = vtkActor::New();

    vtkSmartPointer<T> source(T::New());

    if (setter)
        setter->config(source);

    vtkSmartPointer<vtkPolyDataMapper> mapper(vtkPolyDataMapper::New());
    mapper->SetInputConnection(source->GetOutputPort());
    actor->SetMapper(mapper);

    return actor;
}


template <class DataObject, class Mapper = vtkPolyDataMapper>
static inline vtkActor* createActorFromData(DataObject* data)
{
    vtkActor* actor = vtkActor::New();

    VTK_CREATE(Mapper, mapper);
    mapper->SetInputData(data);
    actor->SetMapper(mapper);

    return actor;
}

void VTKUTILS_EXPORT exportActorToFile(vtkActor* actor, const QString& outfile);

}



#endif // VTKUTILS_H
