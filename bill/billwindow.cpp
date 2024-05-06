#include "billwindow.h"
#include "ui_billwindow.h"
#include <QPushButton>
#include <QDebug>
#include "billdetails.h"

BillWindow::BillWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BillWindow)
{
    ui->setupUi(this);

    populateOrders();

    int row = 0, col = 0;
    for(Order* order : orders){
        qDebug() << "Orders:" << order->getOrderID();
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
}

void BillWindow::populateOrders(){
    MenuItem* pizza = new MenuItem("Pizza", 9.99, "path/to/image/pizza.jpg", "Delicious cheese pizza", Category::MainCourse, {}, Availability::Available);
    MenuItem* burger = new MenuItem("Burger", 5.99, "path/to/image/burger.jpg", "Classic beef burger", Category::MainCourse, {}, Availability::Available);
    MenuItem* soda = new MenuItem("Soda", 1.99, "path/to/image/soda.jpg", "Refreshing soda", Category::Drink, {}, Availability::Available);
    MenuItem* fishNChips = new MenuItem("Fish n Chips", 15.99, "path/to/image/chips.jpg", "Fish and chips", Category::MainCourse, {}, Availability::Available);

    // Creating order items
    OrderItem* orderItem1 = new OrderItem(pizza, 2);
    OrderItem* orderItem2 = new OrderItem(burger, 1);
    OrderItem* orderItem3 = new OrderItem(soda, 3);
    OrderItem* orderItem4 = new OrderItem(fishNChips, 5);

    // Creating orders
    Order* order1 = new Order();
    order1->addItem(orderItem1);
    order1->addItem(orderItem2);

    Order* order2 = new Order();
    order2->addItem(orderItem3);

    Order* order3 = new Order();
    order3->addItem(orderItem4);
    order3->addItem(orderItem3);

    orders.push_back(order1);
    orders.push_back(order2);
    orders.push_back(order3);
}
