#ifndef WIDGET_H
#define WIDGET_H


#include "QVTKOpenGLNativeWidget.h"
#include <vtkSmartPointer.h>

class vtkTextActor;
class VTKWidget : public QVTKOpenGLNativeWidget
{
    Q_OBJECT
public:
    explicit VTKWidget(QWidget* parent = nullptr);

    void setText(const QString& text);

protected:
    void resizeEvent(QResizeEvent *event);

private:
    void layoutTextActor();

    vtkSmartPointer<vtkTextActor> m_textActor;
};

#endif
