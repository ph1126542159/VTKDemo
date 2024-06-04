#ifndef POINTSTOPOLYDATACONVERTER_H
#define POINTSTOPOLYDATACONVERTER_H

#include "point3f.h"
#include "signalledrunable.h"

#include <vtkSmartPointer.h>
#include "vtkutils_global.h"

class vtkPolyData;
namespace VtkUtils
{
class VTKUTILS_EXPORT PointsToPolyDataConverter : public Utils::SignalledRunnable
{
    Q_OBJECT
public:
    explicit PointsToPolyDataConverter(const QList<Utils::Point3F>& points);

    void run();

    vtkPolyData* polyData() const;

private:
    QList<Utils::Point3F> m_points;
    vtkSmartPointer<vtkPolyData> m_polyData;
};

} 
#endif