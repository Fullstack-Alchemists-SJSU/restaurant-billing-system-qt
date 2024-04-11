#ifndef EDITUSERDIALOG_H
#define EDITUSERDIALOG_H

#include <QDialog>
#include "EditUserDialogController.h"

namespace Ui {
class EditUserDialog;
}

class EditUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditUserDialog(const QStringList &row, QWidget *parent = nullptr);
    ~EditUserDialog();

    void populateDefaultFormValues();

private slots:
    void on_editUsername_textChanged(const QString &arg1);

    void on_editPassword_textChanged(const QString &arg1);

    void on_comboRole_currentIndexChanged(int index);

    void onOkClicked();

private:
    Ui::EditUserDialog *ui;
    QPushButton *okButton, *cancelButton;

    const QStringList &row;
    EditUserDialogController *controller;
};

#endif // EDITUSERDIALOG_H
