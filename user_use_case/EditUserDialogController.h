#ifndef EDITUSERDIALOGCONTROLLER_H
#define EDITUSERDIALOGCONTROLLER_H

#include <QtCore/QStringList>
#include "../db/UserManager.h"
#include "../util/Constants.h"

QT_BEGIN_NAMESPACE
namespace Controller {
class EditUserDialogController;
}
QT_END_NAMESPACE

class EditUserDialogController{
private:
    User* originalUser;
    User* editedUser;
    UserManager fileManager;

public:
    EditUserDialogController(User* originalUser, User* editedUser);

    void setEdited(User* newUser);
    User* getEdited();

    bool isRowEdited();

    void updateUser();
    int getNextUserId();
    void addNewUser();
};

#endif // EDITUSERDIALOGCONTROLLER_H
