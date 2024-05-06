#ifndef ORDERDETAILS_H
#define ORDERDETAILS_H

#include <QMainWindow>
#include "models/Order.h"
#include "../menu/Menu.h"
#include "OrderTableAdapter.h"

namespace Ui {
class OrderDetails;
}

class OrderDetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrderDetails(Order* order, Menu* menu, QWidget *parent = nullptr);
    ~OrderDetails();

private slots:
    void on_cbMenu_currentTextChanged(const QString &arg1);

    void on_sbQuantity_valueChanged(int arg1);

    void on_btnAddToOrder_clicked();

    void on_btnCloseOrder_clicked();

    void onOrderClosed();

signals:
    void itemValuesChanged();
    void orderClosed();

private:
    Ui::OrderDetails *ui;
    Order* order;
    Menu* menu;
    OrderItem* itemToAdd;
    OrderTableAdapter adapter;

    QString selectedItemName;
    int selectedQuantity = 0;
    bool itemAlreadyExists = false;

    void decideButtonActive();
};

#endif // ORDERDETAILS_H
