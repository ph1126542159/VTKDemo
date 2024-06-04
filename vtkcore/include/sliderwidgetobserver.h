
#ifndef SLIDERWIDGETOBSERVER_H
#define SLIDERWIDGETOBSERVER_H


#include "abstractwidgetobserver.h"


namespace VtkUtils
{

class VTKUTILS_EXPORT SliderWidgetObserver : public AbstractWidgetObserver
{
public:
    explicit SliderWidgetObserver(QObject* parent = nullptr);

protected:
    void Execute(vtkObject *caller, unsigned long eventId, void* callData);
};

}
#endif // SLIDERWIDGETOBSERVER_H
