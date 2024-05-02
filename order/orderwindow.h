#ifndef ORDERWINDOW_H
#define ORDERWINDOW_H

#include <QMainWindow>
#include "facade/OrderManagementFacade.h"

namespace Ui {
class OrderWindow;
}

class OrderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrderWindow(QWidget *parent = nullptr);
    ~OrderWindow();

private slots:
    void on_btnAddOrder_clicked();

    void on_btnMenu_clicked();

signals:
    void onOrderAdded();

private:
    Ui::OrderWindow *ui;
    OrderManagementFacade* facade;

    void setupOrderGrid();
};

#endif // ORDERWINDOW_H
