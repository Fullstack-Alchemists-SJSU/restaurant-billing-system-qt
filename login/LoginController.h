#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include <QtCore/QString>
#include "../db/FileManager.h"
#include "../util/Constants.h"

QT_BEGIN_NAMESPACE
namespace Controller {
    enum class UserColumnIndexes;
    class LoginController;
}
QT_END_NAMESPACE

enum class UserColumnIndexes{
    ID = 0,
    USERNAME = 1,
    PASSWORD = 2,
    ROLE = 3
};

class LoginController{

private:
    FileManager fileManager;
public:
    LoginController();
    bool login(const QString &username, const QString &password);
};

#endif // LOGINCONTROLLER_H
