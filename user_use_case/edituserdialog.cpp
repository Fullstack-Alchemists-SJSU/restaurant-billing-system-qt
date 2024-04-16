#include "edituserdialog.h"
#include "ui_edituserdialog.h"
#include <QDebug>
#include <QPushButton>

EditUserDialog::EditUserDialog(User* &user, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditUserDialog)
    , user(user)
    , controller(new EditUserDialogController(user, user))
{
    ui->setupUi(this);

    okButton = ui->buttonBox->button(QDialogButtonBox::Ok);    cancelButton = ui->buttonBox->button(QDialogButtonBox::Cancel);
    connect(okButton, &QPushButton::clicked, this, &EditUserDialog::onOkClicked);

    ui->comboRole->blockSignals(true);
    ui->comboRole->addItem(User::enumToString(Role::Admin), QVariant(static_cast<int>(Role::Admin)));
    ui->comboRole->addItem(User::enumToString(Role::StaffMember), QVariant(static_cast<int>(Role::StaffMember)));
    ui->comboRole->addItem(User::enumToString(Role::Accountant), QVariant(static_cast<int>(Role::Accountant)));

    if(user == nullptr){
        this->setWindowTitle("Add New User");
        ui->editUserId->setVisible(false);
        ui->labelUserId->setVisible(false);
        okButton->setEnabled(true);
        ui->comboRole->blockSignals(false);
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
    ui->editUserId->setText(QString::number(user->getUserId()));
    ui->editUsername->setText(user->getUsername());
    ui->editPassword->setText(user->getPassword());
    qDebug() << "Editing: " << user->getUsername() << " role:" << User::enumToString(user->getRole()) << " " << static_cast<int>(user->getRole());
    ui->comboRole->setCurrentIndex(ui->comboRole->findData(static_cast<int>(user->getRole())));
    ui->comboRole->blockSignals(false);
}

void EditUserDialog::on_editUsername_textChanged(const QString &arg1)
{
    if(this->user == nullptr){
        this->newUsername = arg1;
    }else{
        this->user->setUsername(arg1);
    }
}


void EditUserDialog::on_editPassword_textChanged(const QString &arg1)
{
    if(this->user == nullptr){
        this->newPassword = arg1;
    }else{
        this->user->setPassword(arg1);
    }
}


void EditUserDialog::on_comboRole_currentIndexChanged(int index)
{
    if(this->user == nullptr){
        this->newRole = User::intToEnumValue(ui->comboRole->currentData().toInt());
    }else{
        this->user->setRole(User::intToEnumValue(ui->comboRole->currentData().toInt()));
    }
}

void EditUserDialog::onOkClicked(){
    if(user == nullptr){
        this->controller->setEdited(UserFactory::build(this->controller->getNextUserId(), this->newUsername, this->newPassword, this->newRole));
        controller->addNewUser();
    }else{
        this->controller->setEdited(this->user);
        this->controller->updateUser();
    }

    emit operationFinished();
}
