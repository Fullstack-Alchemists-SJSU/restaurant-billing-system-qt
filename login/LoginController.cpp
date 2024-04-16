#include "LoginController.h"
#include <QDebug>

LoginController::LoginController() : fileManager(){}

bool LoginController::login(const QString &username, const QString &password){

    bool isLoginSuccess = false;

    QList<User*> allUsers = fileManager.getAllUsers();
    for(User* user : allUsers){
        if(username.compare(user->getUsername()) == 0 && password.compare(user->getPassword()) == 0){
            return true;
        }
    }
    return false;
}
