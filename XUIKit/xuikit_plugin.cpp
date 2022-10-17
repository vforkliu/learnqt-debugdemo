#include "xuikit_plugin.h"

#include "tomitem.h"
#include "fileutils.h"

#include <qqml.h>
#include <QQmlEngine>
#include <QJSEngine>

void XUIKitPlugin::registerTypes(const char *uri)
{
    // @uri com.xkit.ui
    qmlRegisterType<TomItem>(uri, 1, 0, "TomItem");
    qmlRegisterType(resolveFileUrl(QStringLiteral("FolderTreeView.qml")), uri, 1, 0, "FolderTreeView");
    qmlRegisterSingletonType<FileUtils>(uri, 1, 0, "FM", [](QQmlEngine *engine, QJSEngine *scriptEngine){
            Q_UNUSED(engine)
            Q_UNUSED(scriptEngine)
            return new FileUtils();
        });
}

QString XUIKitPlugin::resolveFileUrl(const QString &filePath) const
{
    return QStringLiteral("qrc:/com/xkit/ui/") + filePath;
}

