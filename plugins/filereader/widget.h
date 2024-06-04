#ifndef WIDGET_H
#define WIDGET_H
#include "QVTKOpenGLNativeWidget.h"
class VTKWidget : public QVTKOpenGLNativeWidget
{
    Q_OBJECT
public:
    explicit VTKWidget(QWidget* parent = nullptr);

};

#endif
