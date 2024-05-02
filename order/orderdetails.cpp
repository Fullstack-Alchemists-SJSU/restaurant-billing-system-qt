#include "orderdetails.h"
#include "ui_orderdetails.h"

OrderDetails::OrderDetails(Order* order, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OrderDetails)
    , order(order)
{
    ui->setupUi(this);
    ui->lbOrderId->setText("Order ID: " + QString::number(order->getOrderID()));
}

OrderDetails::~OrderDetails()
{
    delete ui;
}
