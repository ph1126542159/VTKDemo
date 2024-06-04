#include "vtkutils.h"
#include "actorexporter.h"

#include "vtkImageData.h"
#include "vtkQImageToImageSource.h"

#include <QDebug>
#include <QThreadPool>

namespace VtkUtils {
QImage vtkImageDataToQImage(vtkImageData* imageData)
{
    if (!imageData)
        return QImage();


    int width = imageData->GetDimensions()[0];
    int height = imageData->GetDimensions()[1];
    QImage image(width, height, QImage::Format_RGB32);
    QRgb* rgbPtr = reinterpret_cast<QRgb*>(image.bits()) + width * (height-1);
    unsigned char* colorsPtr = reinterpret_cast<unsigned char*>(
        imageData->GetScalarPointer());

    for(int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {

            *(rgbPtr++) = QColor(colorsPtr[0], colorsPtr[1], colorsPtr[2]).rgb();
            colorsPtr +=  3;
        }
        rgbPtr -= width * 2;
    }
    return image;
}

void qImageToVtkImage(QImage& img, vtkImageData* imageData)
{
    if (!imageData) {
        qDebug() << "null image data.";
        return;
    }

    vtkSmartPointer<vtkQImageToImageSource> qimageToImageSource = vtkSmartPointer<vtkQImageToImageSource>::New();
    qimageToImageSource->SetQImage(&img);
    qimageToImageSource->Update();
    imageData->DeepCopy(qimageToImageSource->GetOutput());
}

void exportActorToFile(vtkActor* actor, const QString& outfile)
{
    VtkUtils::ActorExporter* exporter = new VtkUtils::ActorExporter(actor, outfile);
    QThreadPool::globalInstance()->start(exporter);
}
}
