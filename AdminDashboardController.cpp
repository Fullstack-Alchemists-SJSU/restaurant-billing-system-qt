#include "AdminDashboardController.h"
#include "Constants.h"
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
