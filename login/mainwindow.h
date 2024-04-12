#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "LoginDataModel.h"
#include "LoginController.h"
#include "../admin/admindashboard.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void showMainWindow();

    void on_pushButton_clicked();

    void setModelUsername(const QString &username){
        loginDataModel.setUsername(username);
    }

    void setModelPassword(const QString &password){
        loginDataModel.setPassword(password);
    }

private:
    Ui::MainWindow *ui;
    AdminDashboard* adminDashboard;
    LoginDataModel loginDataModel;
    LoginController loginController;
};
#endif // MAINWINDOW_H
