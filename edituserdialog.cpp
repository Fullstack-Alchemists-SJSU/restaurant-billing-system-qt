#include "edituserdialog.h"
#include "ui_edituserdialog.h"
#include "Constants.h"
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

    populateDefaultFormValues();
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

    okButton->setEnabled(this->controller->isRowEdited());
}

void EditUserDialog::on_editUsername_textChanged(const QString &arg1)
{
    this->controller->setEdited(static_cast<int>(Constants::USERNAME_COLUMN_INDEX), arg1);

    okButton->setEnabled(this->controller->isRowEdited());
}


void EditUserDialog::on_editPassword_textChanged(const QString &arg1)
{
    this->controller->setEdited(static_cast<int>(Constants::PASSWORD_COLUMN_INDEX), arg1);

    okButton->setEnabled(this->controller->isRowEdited());
}


void EditUserDialog::on_comboRole_currentIndexChanged(int index)
{
    this->controller->setEdited(static_cast<int>(Constants::ROLE_COLUMN_INDEX), QString::number(Constants::indexToEnumValue(index)));
    okButton->setEnabled(this->controller->isRowEdited());
}

void EditUserDialog::onOkClicked(){
    this->controller->updateUser();
}

