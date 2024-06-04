
#ifndef CONTOURWIDGETOBSERVER_H
#define CONTOURWIDGETOBSERVER_H

#include "abstractwidgetobserver.h"

#include <vtkSmartPointer.h>


class vtkPolyData;
namespace VtkUtils
{

class VTKUTILS_EXPORT ContourWidgetObserver : public AbstractWidgetObserver
{

public:
    explicit ContourWidgetObserver(QObject* parent = nullptr);
protected:
    void Execute(vtkObject *caller, unsigned long eventId, void* callData)override;

    vtkSmartPointer<vtkPolyData> m_polyData;
};

}
#endif // CONTOURWIDGETOBSERVER_H
