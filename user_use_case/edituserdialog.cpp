#include "edituserdialog.h"
#include "ui_edituserdialog.h"
#include <QDebug>
#include <QPushButton>

EditUserDialog::EditUserDialog(const QStringList &row, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditUserDialog)
    , row(row)
    , controller(new EditUserDialogController(row, row))
{
    ui->setupUi(this);

    okButton = ui->buttonBox->button(QDialogButtonBox::Ok);    cancelButton = ui->buttonBox->button(QDialogButtonBox::Cancel);
    connect(okButton, &QPushButton::clicked, this, &EditUserDialog::onOkClicked);

    ui->comboRole->addItem(Constants::enumToString(Role::Admin), static_cast<int>(Role::Admin));
    ui->comboRole->addItem(Constants::enumToString(Role::StaffMember), static_cast<int>(Role::StaffMember));
    ui->comboRole->addItem(Constants::enumToString(Role::Accountant), static_cast<int>(Role::Accountant));


    if(row.isEmpty()){
        this->setWindowTitle("Add New User");
        ui->editUserId->setVisible(false);
        ui->labelUserId->setVisible(false);
        okButton->setEnabled(true);
    }else{
        this->setWindowTitle("Edit User");
        populateDefaultFormValues();
    }
}

EditUserDialog::~EditUserDialog()
{
    delete ui;
}

void EditUserDialog::populateDefaultFormValues(){
    ui->editUserId->setText(row.at(Constants::USER_ID_COLUMN_INDEX));
    ui->editUsername->setText(row.at(Constants::USERNAME_COLUMN_INDEX));
    ui->editPassword->setText(row.at(Constants::PASSWORD_COLUMN_INDEX));

    ui->comboRole->setCurrentIndex(ui->comboRole->findData(static_cast<QString>(row.at(Constants::ROLE_COLUMN_INDEX))));

    //okButton->setEnabled(this->controller->isRowEdited());
}

void EditUserDialog::on_editUsername_textChanged(const QString &arg1)
{
    this->controller->setEdited(static_cast<int>(Constants::USERNAME_COLUMN_INDEX), arg1);

    //okButton->setEnabled(this->controller->isRowEdited());
}


void EditUserDialog::on_editPassword_textChanged(const QString &arg1)
{
    this->controller->setEdited(static_cast<int>(Constants::PASSWORD_COLUMN_INDEX), arg1);

    //okButton->setEnabled(this->controller->isRowEdited());
}


void EditUserDialog::on_comboRole_currentIndexChanged(int index)
{
    this->controller->setEdited(static_cast<int>(Constants::ROLE_COLUMN_INDEX), QString::number(Constants::indexToEnumValue(index)));
    //okButton->setEnabled(this->controller->isRowEdited());
}

void EditUserDialog::onOkClicked(){
    if(!row.isEmpty()){
        this->controller->updateUser();
    }else{
        QStringList newUserRow;
        newUserRow.insert(Constants::USER_ID_COLUMN_INDEX, QString::number(controller->getNextUserId()));
        newUserRow.insert(Constants::USERNAME_COLUMN_INDEX, ui->editUsername->text());
        newUserRow.insert(Constants::PASSWORD_COLUMN_INDEX, ui->editPassword->text());
        newUserRow.insert(Constants::ROLE_COLUMN_INDEX, QString::number(ui->comboRole->currentIndex() + 1));

        controller->addNewUser(newUserRow);
    }

    emit operationFinished();
}

