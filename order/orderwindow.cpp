#include "orderwindow.h"
#include "ui_orderwindow.h"
#include "../menu/MenuWindow.h"
#include <QDebug>
#include "orderdetails.h"
#include "../util/Constants.h"

OrderWindow::OrderWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OrderWindow)
    , facade(new OrderManagementFacade())
{
    ui->setupUi(this);
    ui->scrollArea->setWidgetResizable(true);

    // Load orders from file
    facade->loadOrdersFromFile(Constants::ORDER_FILE.toStdString());
    setupOrderGrid();

    connect(this, &OrderWindow::onOrderAdded, this, &OrderWindow::setupOrderGrid);
}

OrderWindow::~OrderWindow()
{
    delete ui;
}

void OrderWindow::setupOrderGrid(){
    ui->glOrder->invalidate();
    int row = 0, col = 0;
    for(Order* order : facade->getOrders()){
        QPushButton *button = new QPushButton(QString("Order %1").arg(order->getOrderID()));
        connect(button, &QPushButton::clicked, this, [this, order](){
            OrderDetails* details = new OrderDetails(order, facade->getMenu(), this);
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

void OrderWindow::on_btnAddOrder_clicked()
{
    facade->createOrder();
    emit onOrderAdded();
}


void OrderWindow::on_btnMenu_clicked()
{
    MenuWindow* menuWindow = new MenuWindow(new Menu(), this);
    menuWindow->show();
}

