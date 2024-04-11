#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QFile>
#include <QTextStream>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Manager {
    class FileManager;
}
QT_END_NAMESPACE

class FileManager{
private:
    QString fileName;
public:
    FileManager(const QString& filename);
    QList<QStringList> read(bool skipEmptyParts = false);
    void write(const QList<QStringList>& data);
    void update(int id, const QStringList& newRow);
};

#endif // FILEMANAGER_H
