
#ifndef ANIMATIONPLUGIN_H
#define ANIMATIONPLUGIN_H

#include "ivtkplugin.h"

class AnimationPlugin : public QObject, public Utils::IVtkPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "QVTKDemos.AnimationPlugin")
    Q_INTERFACES(Utils::IVtkPlugin)
public:
    AnimationPlugin();
    ~AnimationPlugin();

    QString category() const;
    QList<QWidget *> examples() const;
    QStringList keywords() const;
};

#endif // ANIMATIONPLUGIN_H
