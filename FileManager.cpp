#include "FileManager.h"
#include <QDebug>
FileManager::FileManager(const QString& filename) : fileName(filename) {}

QList<QString> FileManager::read() {
    QList<QString> data;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for reading:" << file.errorString();
        return data;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        data.append(line);
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

// Update a row by ID
void FileManager::update(int id, const QStringList& newRow) {
    // QList<QString> data = read();

    // // Find and update the row with the matching ID
    // for (QString& row : data) {
    //     if (row.size() > 0 && row[0].toInt() == id) {
    //         row = newRow;
    //         break;
    //     }
    // }

    // write(data);
}
