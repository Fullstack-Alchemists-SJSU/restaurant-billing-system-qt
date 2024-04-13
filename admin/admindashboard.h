#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include "../user_use_case/edituserdialog.h"
#include "AdminDashboardController.h"
#include "../util/Constants.h"

namespace Ui {
class AdminDashboard;
}

class AdminDashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminDashboard(QWidget *parent = nullptr);
    ~AdminDashboard();
signals:
    void backNavigationRequested();

private slots:
    void on_buttonLogout_clicked();
    void editUserClicked(int row);
    void deleteUserClicked(int row);

    void on_pushButton_clicked();

private:
    Ui::AdminDashboard *ui;
    AdminDashboardController controller;
    EditUserDialog *editUserDialog;

    void setupTable();
    void showUserDialog(int row);

    static QPushButton* iconButton(QString iconPath){
        QIcon icon(iconPath);
        QPushButton* iconPushButton = new QPushButton();
        iconPushButton->setIcon(icon);
        iconPushButton->setIconSize(QSize(24, 24));

        return iconPushButton;
    }

    static QWidget* actionsColumnWidget(AdminDashboard* instance, int row){
        QWidget* containerWidget = new QWidget();
        QHBoxLayout* layout = new QHBoxLayout(containerWidget);

        QPushButton *editButton = iconButton(Constants::EDIT_SVG);
        connect(editButton, &QPushButton::clicked, instance, [=](){
            instance->editUserClicked(row);
        });

        QPushButton *deleteButton = iconButton(Constants::DELETE_SVG);
        connect(deleteButton, &QPushButton::clicked, instance, [=](){
            instance->deleteUserClicked(row);
        });


        layout->addWidget(editButton);
        layout->addWidget(deleteButton);
        layout->setContentsMargins(4, 2, 4, 2);
        containerWidget->setLayout(layout);
        return containerWidget;
    }
};

#endif // ADMINDASHBOARD_H
