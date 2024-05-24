#include "billwindow.h"
#include "QtCore/qjsonobject.h"
#include "ui_billwindow.h"
#include <QPushButton>
#include <QDebug>
#include "billdetails.h"
#include "../util/Constants.h"

BillWindow::BillWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BillWindow)
    , facade(new OrderManagementFacade())
{
    ui->setupUi(this);

    populateOrders();

    int row = 0, col = 0;
    for(Order* order : orders){
        // qDebug() << "Orders:" << order->getOrderID();
        QPushButton *button = new QPushButton(QString("Order %1").arg(order->getOrderID()));
        connect(button, &QPushButton::clicked, this, [this, order](){
            BillDetails* details = new BillDetails(order, this);
            details->show();
        });
        ui->glOrder->addWidget(button, row, col, Qt::AlignTop);
        col++;

        if(col >= 4){
            col = 0;
            row++;
        }
    }
}

BillWindow::~BillWindow()
{
    delete ui;
    delete facade;
}

void BillWindow::populateOrders(){
    // Load orders from CSV file using OrderManagementFacade
    facade->loadOrdersFromFile(Constants::ORDER_FILE.toStdString());
    orders = facade->getOrders();

    // for(Order* order : orders){
    //     qDebug() << "Order ID:" << order->getOrderID();
    //     qDebug() << "Order count:" << order->getItemCount();
    //     for(OrderItem* item : order->getItems()){
    //         qDebug() << "Item Name:" << QString::fromStdString(item->getMenuItemName())
    //                  << "Quantity:" << item->getQuantity()
    //                  << "Price:" << item->getMenuItem()->getPrice();
    //     }
    // }
}
