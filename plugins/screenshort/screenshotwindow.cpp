#include "screenshotwindow.h"
#include "ui_screenshotwindow.h"

#include "utils.h"
#include <vtkwidget.h>
#include <vtkutils.h>

#include <vtkPlatonicSolidSource.h>
#include <vtkActor.h>
#include <vtkWindowToImageFilter.h>

#include <QFileDialog>
#include <QFileInfo>
#include <QProcess>

ScreenshotWindow::ScreenshotWindow(QWidget* parent) :
    QWidget(parent),
    m_ui(new Ui::ScreenshotWindow)
{
    m_ui->setupUi(this);

    m_vtkWidget = new VtkUtils::VtkWidget(this);
    m_ui->previewLayout->addWidget(m_vtkWidget);

    m_vtkWidget->addActor(VtkUtils::createSourceActor<vtkPlatonicSolidSource>());

    setWindowTitle(tr("Screenshot demo"));
}

ScreenshotWindow::~ScreenshotWindow()
{
    delete m_ui;
}

void ScreenshotWindow::on_exportButton_clicked()
{
    QString exportFile = QFileDialog::getSaveFileName(this, tr("Export screenshot"), ".",
        "PNG Files(*.png);;JPG Files(*.jpg);;BMP Files(*.bmp)");
    if (exportFile.isEmpty())
        return;

    QFileInfo fi(exportFile);
    const QString ext = fi.suffix().toLower();

    vtkNew <vtkWindowToImageFilter> windowToImageFilter;
    vtkWindow* ptrWnd=reinterpret_cast<vtkWindow*>(m_vtkWidget->renderWindow());
    windowToImageFilter->SetInput(ptrWnd);
    windowToImageFilter->SetScale(2);
    windowToImageFilter->SetInputBufferTypeToRGBA();
    windowToImageFilter->ReadFrontBufferOff();
    windowToImageFilter->Update();


    QImage image = VtkUtils::vtkImageDataToQImage(windowToImageFilter->GetOutput());
    image.save(exportFile, ext.toUtf8().data());

    m_ui->exportPathLabel->setText(exportFile);
}

void ScreenshotWindow::on_browseButton_clicked()
{
    Utils::explorer(m_ui->exportPathLabel->text());
}
