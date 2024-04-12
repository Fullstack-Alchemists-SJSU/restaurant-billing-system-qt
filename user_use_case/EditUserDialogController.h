#ifndef EDITUSERDIALOGCONTROLLER_H
#define EDITUSERDIALOGCONTROLLER_H

#include <QtCore/QStringList>
#include "../db/FileManager.h"
#include "../util/Constants.h"

QT_BEGIN_NAMESPACE
namespace Controller {
class EditUserDialogController;
}
QT_END_NAMESPACE

class EditUserDialogController{
private:
    QStringList originalRow, editedRow;
    FileManager fileManager;

public:
    EditUserDialogController(QStringList originalRow, QStringList editedRow);

    void setEdited(int columnIndex, QString newValue);
    void setEdited(QStringList newRow);
    QStringList getEdited();

    bool isRowEdited();

    void updateUser();
    int getNextUserId();
    void addNewUser(QStringList newUser);
};

#endif // EDITUSERDIALOGCONTROLLER_H
