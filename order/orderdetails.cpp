#include "orderdetails.h"
#include "controllers/OrderController.h"
#include "ui_orderdetails.h"
#include <QWidget>
#include <QDebug>
#include "../bill/bill.h"
#include <QDateTime>
#include "../util/Constants.h"

OrderDetails::OrderDetails(Order* order, Menu* menu, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OrderDetails)
    , order(order)
    , menu(menu)
{
    ui->setupUi(this);
    ui->lbOrderId->setText("Order ID: " + QString::number(order->getOrderID()));

    for(MenuItem item: menu->getMenuItems()){
        ui->cbMenu->addItem(QString::fromStdString(item.getName()));
    }
    adapter.setOrderItems(order->getItems());
    ui->tvItems->setModel(&adapter);
    ui->tvItems->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(this, &OrderDetails::itemValuesChanged, this, &OrderDetails::decideButtonActive);

    if(order->getStatus().compare("Open") == 0){
        ui->btnCloseOrder->setVisible(true);
    }else{
        ui->btnCloseOrder->setVisible(false);
    }

    connect(this, &OrderDetails::orderClosed, this, &OrderDetails::onOrderClosed);
}

OrderDetails::~OrderDetails()
{
    delete ui;
}

void OrderDetails::on_cbMenu_currentTextChanged(const QString &arg1)
{
    for(OrderItem* item: order->getItems()){
        if(item->getMenuItem()->getName().compare(arg1.toStdString()) == 0){
            itemAlreadyExists = true;
            break;
        }else{
            itemAlreadyExists = false;
        }
    }
    selectedItemName = arg1;
    emit itemValuesChanged();
}


void OrderDetails::on_sbQuantity_valueChanged(int arg1)
{
    selectedQuantity = arg1;
    emit itemValuesChanged();
}


void OrderDetails::on_btnAddToOrder_clicked()
{
    MenuItem* menuItem = nullptr;
    for(MenuItem item : menu->getMenuItems()){
        if(item.getName().compare(selectedItemName.toStdString()) == 0){
            menuItem = new MenuItem(item);
            break;
        }
    }

    if(menuItem != nullptr){
        itemToAdd = new OrderItem(menuItem, selectedQuantity);
        order->addItem(itemToAdd);
    }

    adapter.setOrderItems(order->getItems());
    itemAlreadyExists = false;
}

void OrderDetails::decideButtonActive(){
    if(itemAlreadyExists || selectedQuantity < 1){
        ui->btnAddToOrder->setDisabled(true);
    }else{
        ui->btnAddToOrder->setDisabled(false);
    }
}


void OrderDetails::on_btnCloseOrder_clicked()
{
    order->setStatus("Closed");
    emit orderClosed();

}

void OrderDetails::onOrderClosed(){
    ui->btnCloseOrder->setVisible(false);
    Bill bill(1, order, QDateTime::currentDateTime().toString().toStdString());
    qDebug() << "Total: " << bill.calculateTotal();

    // Save order to file
    OrderController controller;
    controller.setOrder(order);
    controller.saveOrderToFile(Constants::ORDER_FILE.toStdString());
}
