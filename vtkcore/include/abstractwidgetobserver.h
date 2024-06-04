
#ifndef ABSTRACTWIDGETOBSERVER_H
#define ABSTRACTWIDGETOBSERVER_H


#include <QObject>

#include <vtkCommand.h>

#include "vtkutils_global.h"

class vtkInteractorObserver;
class vtkPolyData;
namespace VtkUtils
{

class VTKUTILS_EXPORT AbstractWidgetObserver : public QObject, public vtkCommand
{
    Q_OBJECT
public:
    explicit AbstractWidgetObserver(QObject *parent = 0);
    virtual ~AbstractWidgetObserver();
    void attach(vtkInteractorObserver* widget);
signals:
    void dataChanged(vtkPolyData* data);
    void distanceChanged(double dist);
    void worldPoint1Changed(double* pos);
    void worldPoint2Changed(double* pos);
    void displayPoint1Changed(double* pos);
    void displayPoint2Changed(double* pos);
    void valueChanged(double value);
protected:
    vtkInteractorObserver* m_widget = nullptr;
};

}
#endif // ABSTRACTWIDGETOBSERVER_H
