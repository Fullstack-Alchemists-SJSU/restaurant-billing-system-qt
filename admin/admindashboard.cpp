#include "admindashboard.h"
#include "ui_admindashboard.h"
#include <QDebug>

AdminDashboard::AdminDashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminDashboard)
{
    ui->setupUi(this);
    setupTable();
}

AdminDashboard::~AdminDashboard()
{
    delete ui;
}


void AdminDashboard::on_buttonLogout_clicked()
{
    emit backNavigationRequested();
}

void AdminDashboard::showUserDialog(User* user = nullptr){
    editUserDialog = new EditUserDialog(user, this);
    connect(editUserDialog, &EditUserDialog::operationFinished, this, &AdminDashboard::setupTable);
    editUserDialog->exec();
}

void AdminDashboard::editUserClicked(User* user){
    showUserDialog(user);
}

void AdminDashboard::setupTable(){
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    UserTableModelAdapter *model = controller.populateTable();
    ui->tableView->setModel(model);

    for(int lineIndex = 0; lineIndex < model->rowCount(); lineIndex++){
        QModelIndex index = model->index(lineIndex, Constants::ACTIONS_COLUMN_INDEX);
        ui->tableView->setIndexWidget(index, actionsColumnWidget(this, this->controller.getAllUsers().at(lineIndex)));
    }

    ui->tableView->update();
}

void AdminDashboard::deleteUserClicked(User* user){
    controller.deleteUser(user);
    setupTable();
}

void AdminDashboard::on_pushButton_clicked()
{
    showUserDialog();
}

