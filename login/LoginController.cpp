#include "LoginController.h"
#include <QDebug>

LoginController::LoginController() : fileManager(Constants::USER_FILE){}

bool LoginController::login(const QString &username, const QString &password){

    bool isLoginSuccess = false;

    QList<QStringList> rows = fileManager.read();
    for(QStringList row : rows){
        if(username.compare(row[static_cast<int>(UserColumnIndexes::USERNAME)]) == 0 && password.compare(row[static_cast<int>(UserColumnIndexes::PASSWORD)]) == 0){
            return true;
        }
    }
    return false;
}
