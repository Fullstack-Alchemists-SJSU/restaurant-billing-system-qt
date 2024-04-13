#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->hSpacerStart->changeSize(this->size().width() / 3, this->size().height());
    ui->hSpacerEnd->changeSize(this->size().width() / 3, this->size().height());

    ui->vSpacerForm->changeSize(0, this->size().height() * 0.10);
    ui->vSpacerUsername->changeSize(0, this->size().height() * 0.01);

    connect(ui->editUsername, &QLineEdit::textChanged, this, &MainWindow::setModelUsername);
    connect(ui->editPassword, &QLineEdit::textChanged, this, &MainWindow::setModelPassword);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showMainWindow(){
    this->show();
    disconnect(adminDashboard, &AdminDashboard::backNavigationRequested, this, &MainWindow::showMainWindow);
    adminDashboard->deleteLater();
}

void MainWindow::on_pushButton_clicked()
{
    /*if(loginDataModel.getUsername().isEmpty() || loginDataModel.getPassword().isEmpty()){
        QMessageBox::critical(this, "Error", "Username or password cannot be empty");
        return;
    }else{*/
        //bool loginSuccess = loginController.login(loginDataModel.getUsername(), loginDataModel.getPassword());
        bool loginSuccess = loginController.login("shivam.hasurkar", "admin@123");

        if(loginSuccess){
            adminDashboard = new AdminDashboard(this);
            adminDashboard->setAttribute(Qt::WA_DeleteOnClose);
            connect(adminDashboard, &AdminDashboard::backNavigationRequested, this, &MainWindow::showMainWindow);
            adminDashboard->show();
            this->hide();
        }else{
            QMessageBox::critical(this, "Invalid credentials", "Please enter valid username and password");
        }
    //}
}

