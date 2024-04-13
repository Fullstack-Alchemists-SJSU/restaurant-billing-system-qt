#ifndef LOGINDATAMODEL_H
#define LOGINDATAMODEL_H

#include <QtCore/QString>

QT_BEGIN_NAMESPACE
namespace Model {
    class LoginDataModel;
}
QT_END_NAMESPACE

class LoginDataModel{
private:
    QString username, password;
public:
    void setUsername(const QString &username);
    void setPassword(const QString &password);
    QString getUsername();
    QString getPassword();
};

#endif // LOGINDATAMODEL_H
