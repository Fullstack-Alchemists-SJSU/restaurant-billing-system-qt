#include "LoginDataModel.h"
void LoginDataModel::setUsername(const QString &username){
    this->username = username;
}

void LoginDataModel::setPassword(const QString &password){
    this->password = password;
}

QString LoginDataModel::getUsername(){
    return this->username;
}

QString LoginDataModel::getPassword(){
    return this->password;
}
