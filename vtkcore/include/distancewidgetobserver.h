
#ifndef DISTANCEWIDGETOBSERVER_H
#define DISTANCEWIDGETOBSERVER_H


#include "abstractwidgetobserver.h"
namespace VtkUtils
{

class VTKUTILS_EXPORT DistanceWidgetObserver : public AbstractWidgetObserver
{
public:
    explicit DistanceWidgetObserver(QObject* parent = nullptr);

protected:
    void Execute(vtkObject *caller, unsigned long eventId, void* callData)override;
};

}
#endif // DISTANCEWIDGETOBSERVER_H
