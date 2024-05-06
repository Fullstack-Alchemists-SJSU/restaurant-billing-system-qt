#include "billdetails.h"
#include "ui_billdetails.h"
#include <QDateTime>
#include "bill.h"

BillDetails::BillDetails(Order* order, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BillDetails)
    , order(order)
    , adapter(new OrderTableAdapter(this))
{
    ui->setupUi(this);

    ui->lbBillNumber->setText("Bill Number: " + QString::number(QDateTime::currentSecsSinceEpoch()));
    ui->lbBillDate->setText(QDateTime::currentDateTimeUtc().toString());

    adapter->setOrderItems(order->getItems());
    ui->tvOrderItems->setModel(adapter);
    ui->tvOrderItems->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    Bill* bill = new Bill(1, order, QDateTime::currentDateTimeUtc().toString().toStdString());

    ui->lcdTotal->display(bill->calculateTotal());

    QPalette palette = ui->lcdTotal->palette();
    palette.setColor(QPalette::WindowText, QColor(Qt::black));
    palette.setColor(palette.Dark, QColor(255, 0, 0));
    ui->lcdTotal->setPalette(palette);
}

BillDetails::~BillDetails()
{
    delete ui;
}
