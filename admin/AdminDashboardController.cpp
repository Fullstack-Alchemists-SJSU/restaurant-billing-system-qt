#include "AdminDashboardController.h"
#include <QDebug>


AdminDashboardController::AdminDashboardController(): fileManager(){}


UserTableModelAdapter* AdminDashboardController::populateTable(){

    QList<User*> allUsers = fileManager.getAllUsers();
    UserTableModelAdapter *model = new UserTableModelAdapter;
    model->setUsers(allUsers);
    this->allUsers = allUsers;
    return model;
}

void AdminDashboardController::deleteUser(User* user){
    fileManager.deleteUser(user);
}

QList<User*> AdminDashboardController::getAllUsers(){
    return this->allUsers;
}
