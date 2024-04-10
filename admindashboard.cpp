#include "admindashboard.h"
#include "ui_admindashboard.h"

AdminDashboard::AdminDashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminDashboard)
{
    ui->setupUi(this);
}

AdminDashboard::~AdminDashboard()
{
    delete ui;
}


void AdminDashboard::on_buttonLogout_clicked()
{
    emit backNavigationRequested();
}

