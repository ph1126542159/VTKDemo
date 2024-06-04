#ifndef IVTKPLUGIN_H
#define IVTKPLUGIN_H

#include "iplugin.h"
#include "utils_global.h"

namespace Utils
{

class UTILS_EXPORT IVtkPlugin : public IPlugin
{
public:
    IVtkPlugin();
    virtual ~IVtkPlugin();

    virtual QString category() const = 0;
    virtual QList<QWidget*> examples() const = 0;
    virtual QStringList keywords() const = 0;
};

} // namespace Utils

QT_BEGIN_NAMESPACE
#define IVtkPlugin_IID "QVTKDemos.IVtkPlugin"
Q_DECLARE_INTERFACE(Utils::IVtkPlugin,IVtkPlugin_IID)
QT_END_NAMESPACE

#endif
