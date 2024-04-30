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
protected:
    FileManager(const QString& filename);
    QList<QStringList> read(bool skipEmptyParts = false);
    void write(const QList<QStringList>& data);
    void appendAtEnd(QStringList newRow);
    void update(int id, const QStringList& newRow);
    void deleteRowAtIndex(int id);
};

#endif // FILEMANAGER_H
