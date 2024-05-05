#include "orderdetails.h"
#include "ui_orderdetails.h"
#include <QWidget>
#include <QDebug>

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
    qDebug() << "item: " << itemAlreadyExists << selectedQuantity;
    if(itemAlreadyExists || selectedQuantity < 1){
        ui->btnAddToOrder->setDisabled(true);
    }else{
        ui->btnAddToOrder->setDisabled(false);
    }
}

