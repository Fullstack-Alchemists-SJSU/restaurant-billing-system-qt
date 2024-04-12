#include "AdminDashboardController.h"
#include <QDebug>


AdminDashboardController::AdminDashboardController(): fileManager(Constants::USER_FILE){}


QStandardItemModel* AdminDashboardController::populateTable(){

    QList<QStringList> rows = fileManager.read(true);
    QStandardItemModel *model = new QStandardItemModel(rows.size() - 1, rows.first().size() + 1);
    for(int lineIndex = 0; lineIndex < rows.size(); lineIndex++){
        QStringList row = rows.at(lineIndex);
        if(lineIndex == 0){
            row.append("Actions");
            model->setHorizontalHeaderLabels(row);
        }else{
            for(int i = 0; i < row.size(); i++){
                QString value = row.at(i);
                QStandardItem *item = new QStandardItem(value);
                item->setFlags(Qt::ItemIsEnabled);
                model->setItem(lineIndex - 1, i, item);
            }
        }
    }

    return model;
}

void AdminDashboardController::deleteUser(int row){
    QList<QStringList> rows = fileManager.read(true);
    fileManager.deleteUser(rows.at(row + 1).at(Constants::USER_ID_COLUMN_INDEX).toInt()); //row + 1 because 0 indexing
}
