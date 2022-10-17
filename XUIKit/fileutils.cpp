#include "fileutils.h"
#include <QStandardPaths>

FileUtils::FileUtils(QObject* parent):
    QObject(parent)
{

}

QString FileUtils::homePath()
{
    return QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).first();
}
