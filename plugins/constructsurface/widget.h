#ifndef WIDGET_H
#define WIDGET_H

#include <vtkAutoInit.h>
#include "QVTKOpenGLNativeWidget.h"

namespace Utils
{
    class TableModel;
}

class vtkActor;
class VTKWidget : public QVTKOpenGLNativeWidget
{
    Q_OBJECT
public:
    explicit VTKWidget(QWidget* parent = nullptr);

    void setModel(Utils::TableModel* model);

private slots:
    void onModelDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);

private:
    void constructSurfaceFromModel(Utils::TableModel* model);

    vtkActor* m_surfaceActor = nullptr;
};

#endif
