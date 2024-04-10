#include "LoginController.h"
#include <QDebug>

LoginController::LoginController() : fileManager(fileName){}

bool LoginController::login(const QString &username, const QString &password){

    bool isLoginSuccess = false;

    QList<QString> rows = fileManager.read();
    for(QString row : rows){
        auto fields = row.split(",");
        if(username.compare(fields[static_cast<int>(UserColumnIndexes::USERNAME)]) == 0 && password.compare(fields[static_cast<int>(UserColumnIndexes::PASSWORD)]) == 0){
            return true;
        }
    }
    return false;
}
