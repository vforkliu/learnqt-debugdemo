#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <QObject>
class FileUtils:public QObject
{
    Q_OBJECT
public:
    FileUtils(QObject* parent = nullptr);
    Q_INVOKABLE QString homePath();


};

#endif // FILEUTILS_H
