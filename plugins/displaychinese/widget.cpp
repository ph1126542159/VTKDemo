#include "widget.h"

#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkPolyDataMapper.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>

#include <QDebug>

VTKWidget::VTKWidget(QWidget* parent) : QVTKOpenGLNativeWidget(parent)
{
    vtkObject::GlobalWarningDisplayOff();

    renderWindow()->SetMultiSamples(0);

    vtkRenderer* renderer = vtkRenderer::New();

    QString text = "你好 VTK";
    m_textActor = vtkTextActor::New();
    m_textActor->GetTextProperty()->SetFontFamily(VTK_FONT_FILE);
    m_textActor->GetTextProperty()->SetFontSize(20);
    m_textActor->GetTextProperty()->SetFontFile("E:/minisong.ttf");


    m_textActor->SetInput(text.toLocal8Bit().data());
    renderer->AddActor(m_textActor);

    renderWindow()->AddRenderer(renderer);

    setWindowTitle(tr("QVTK Tutorial: Display Chinese characters"));
}

void VTKWidget::resizeEvent(QResizeEvent* event)
{
    Q_UNUSED(event)
        layoutTextActor();
}

void VTKWidget::layoutTextActor()
{
    if (m_textActor) {
        QString text(m_textActor->GetInput()); 
        qreal textLenght = fontMetrics().horizontalAdvance(text);
        m_textActor->SetPosition(width() / 2 - textLenght / 2, height() / 2);
    }
}

void VTKWidget::setText(const QString& text)
{
    m_textActor->SetInput(text.toLocal8Bit().data());
    layoutTextActor();
    update();
}
