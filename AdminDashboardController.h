#ifndef ADMINDASHBOARDCONTROLLER_H
#define ADMINDASHBOARDCONTROLLER_H

#include<QtCore/QString>
#include <QStandardItemModel>
#include "FileManager.h"
#include <QTableView>

QT_BEGIN_NAMESPACE
namespace Controller {
    class AdminDashboardController;
}
QT_END_NAMESPACE

class AdminDashboardController{
private:
    FileManager fileManager;

public:
    AdminDashboardController();
    QStandardItemModel* populateTable();
    void deleteUser(int id);
};

QT_END_NAMESPACE
#endif // ADMINDASHBOARDCONTROLLER_H
