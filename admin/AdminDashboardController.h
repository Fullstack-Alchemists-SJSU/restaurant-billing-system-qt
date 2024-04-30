#ifndef ADMINDASHBOARDCONTROLLER_H
#define ADMINDASHBOARDCONTROLLER_H

#include<QtCore/QString>
#include <QStandardItemModel>
#include "../db/UserManager.h"
#include "../util/Constants.h"
#include "UserTableModelAdapter.h"
#include <QTableView>

QT_BEGIN_NAMESPACE
namespace Controller {
    class AdminDashboardController;
}
QT_END_NAMESPACE

class AdminDashboardController{
private:
    UserManager fileManager;
    QList<User*> allUsers;

public:
    AdminDashboardController();
    UserTableModelAdapter* populateTable();
    void deleteUser(User* user);

    QList<User*> getAllUsers();
};

QT_END_NAMESPACE
#endif // ADMINDASHBOARDCONTROLLER_H
