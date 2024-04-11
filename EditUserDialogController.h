#ifndef EDITUSERDIALOGCONTROLLER_H
#define EDITUSERDIALOGCONTROLLER_H

#include <QtCore/QStringList>
#include "FileManager.h"

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
    QStringList getEdited();

    bool isRowEdited();

    void updateUser();
};

#endif // EDITUSERDIALOGCONTROLLER_H
