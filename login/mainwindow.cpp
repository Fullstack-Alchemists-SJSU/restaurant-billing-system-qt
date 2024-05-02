#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../menu/MenuWindow.h"
#include "../order/orderwindow.h"
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
    if(nextWindow != nullptr){
        if(dynamic_cast<AdminDashboard*>(nextWindow)){
            disconnect((AdminDashboard*) nextWindow, &AdminDashboard::backNavigationRequested, this, &MainWindow::showMainWindow);
        }
        nextWindow->deleteLater();
    }
}

void MainWindow::on_pushButton_clicked()
{
    // if(loginDataModel.getUsername().isEmpty() || loginDataModel.getPassword().isEmpty()){
    //     QMessageBox::critical(this, "Error", "Username or password cannot be empty");
    //     return;
    // }else{
        //User* loggedInUser = loginController.login(loginDataModel.getUsername(), loginDataModel.getPassword());

        User* loggedInUser = loginController.login("vijitha.gunta", "viji");
        if(loggedInUser != nullptr){
            switch (loggedInUser->getRole()) {
            case Role::Admin:
                nextWindow = new AdminDashboard(this);
                connect((AdminDashboard*) nextWindow, &AdminDashboard::backNavigationRequested, this, &MainWindow::showMainWindow);
                break;
            case Role::StaffMember:

                //nextWindow = new MenuWindow(nullptr, this);
                nextWindow = new OrderWindow(this);
            case Role::Accountant:
                //TODO: Add navigation for accountant
            default:
                break;
            }
            nextWindow->setAttribute(Qt::WA_DeleteOnClose);
            nextWindow->show();
            this->hide();
        }else{
            QMessageBox::critical(this, "Invalid credentials", "Please enter valid username and password");
        }
    //}
}

