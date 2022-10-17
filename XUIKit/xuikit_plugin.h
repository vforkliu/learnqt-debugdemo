#ifndef XUIKIT_PLUGIN_H
#define XUIKIT_PLUGIN_H

#include <QQmlExtensionPlugin>

class XUIKitPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
    QString resolveFileUrl(const QString &filePath) const;
};

#endif // XUIKIT_PLUGIN_H
