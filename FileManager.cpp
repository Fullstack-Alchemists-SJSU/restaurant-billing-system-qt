#include "FileManager.h"
#include <QDebug>

FileManager::FileManager(const QString& filename) : fileName(filename) {}

QList<QStringList> FileManager::read(bool skipEmptyParts) {
    QList<QStringList> data;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for reading:" << file.errorString();
        return data;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if(skipEmptyParts){
            data.append(line.split(",", Qt::SkipEmptyParts));
        }else{
            data.append(line.split(","));
        }
    }

    file.close();
    return data;
}

void FileManager::write(const QList<QStringList>& data) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for writing:" << file.errorString();
        return;
    }

    QTextStream out(&file);
    for (const QStringList& row : data) {
        out << row.join(",") << "\n";
    }

    file.close();
}

void FileManager::update(int id, const QStringList& newRow) {
    QList<QStringList> data = read();

    // Find and update the row with the matching ID
    for (QStringList &row : data) {
        if (row.size() > 0 && row[0].toInt() == id) {
            row = newRow;
            break;
        }
    }

    write(data);
}
