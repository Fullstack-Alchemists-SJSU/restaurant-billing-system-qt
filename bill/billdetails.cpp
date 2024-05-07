#include "billdetails.h"
#include "ui_billdetails.h"
#include <QDateTime>
#include <QMessageBox>
#include "bill.h"

BillDetails::BillDetails(Order* order, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BillDetails)
    , order(order)
    , adapter(new OrderTableAdapter(this))
{
    ui->setupUi(this);

    connect(ui->btnApplyCoupon, &QPushButton::clicked, this, &BillDetails::applyCouponDiscount);
    connect(ui->btnApplyParty, &QPushButton::clicked, this, &BillDetails::applyPartyDiscount);
    connect(ui->btnApplySeasonal, &QPushButton::clicked, this, &BillDetails::applySeasonalDiscount);

    connect(ui->btnMakePayment, &QPushButton::clicked, this, &BillDetails::makePayment);


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


void BillDetails::applyCouponDiscount() {
    // Assuming you have a method to apply the coupon discount
    // Update the bill and UI accordingly
}

void BillDetails::applyPartyDiscount() {
    // Assuming you have a method to apply the party discount
    // Update the bill and UI accordingly
}

void BillDetails::applySeasonalDiscount() {
    // Assuming you have a method to apply the seasonal discount
    // Update the bill and UI accordingly
}



void BillDetails::makePayment() {
    // Process the payment and perhaps close the window or show a confirmation
    QMessageBox::information(this, "Payment Confirmation", "Your Payment was successful");
}

BillDetails::~BillDetails()
{
    delete ui;
}
