#ifndef EDITUSERDIALOG_H
#define EDITUSERDIALOG_H

#include <QDialog>
#include "EditUserDialogController.h"
#include "../util/Constants.h"

namespace Ui {
class EditUserDialog;
}

class EditUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditUserDialog(User* &user, QWidget *parent = nullptr);
    ~EditUserDialog();

    void populateDefaultFormValues();

private slots:
    void on_editUsername_textChanged(const QString &arg1);

    void on_editPassword_textChanged(const QString &arg1);

    void on_comboRole_currentIndexChanged(int index);

    void onOkClicked();

signals:
    void operationFinished();

private:
    Ui::EditUserDialog *ui;
    QPushButton *okButton, *cancelButton;

    QString newUsername, newPassword;
    Role newRole;
    User* &user;
    EditUserDialogController *controller;
};

#endif // EDITUSERDIALOG_H
