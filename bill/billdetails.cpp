#include "billdetails.h"
#include "ui_billdetails.h"
#include <QDateTime>
#include <QMessageBox>
#include "bill.h"
#include <iostream>

BillDetails::BillDetails(Order* order, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BillDetails)
    , order(order)
    , adapter(new OrderTableAdapter(this))
    ,  bill(new Bill(1, order, QDateTime::currentDateTimeUtc().toString().toStdString()))  // Initialize bill here
{
    ui->setupUi(this);
    ui->labelDiscountStatus->setText("");
    connect(ui->btnApplyCoupon, &QPushButton::clicked, this, &BillDetails::applyCouponDiscount);
    connect(ui->btnApplyParty, &QPushButton::clicked, this, &BillDetails::applyPartyDiscount);
    connect(ui->btnApplySeasonal, &QPushButton::clicked, this, &BillDetails::applySeasonalDiscount);

    connect(ui->btnMakePayment, &QPushButton::clicked, this, &BillDetails::makePayment);


    ui->lbBillNumber->setText("Bill Number: " + QString::number(QDateTime::currentSecsSinceEpoch()));
    ui->lbBillDate->setText(QDateTime::currentDateTimeUtc().toString());

    adapter->setOrderItems(order->getItems());
    ui->tvOrderItems->setModel(adapter);
    ui->tvOrderItems->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //Bill* bill = new Bill(1, order, QDateTime::currentDateTimeUtc().toString().toStdString());

    ui->lcdTotal->display(bill->calculateTotal());

    QPalette palette = ui->lcdTotal->palette();
    palette.setColor(QPalette::WindowText, QColor(Qt::black));
    palette.setColor(palette.Dark, QColor(255, 0, 0));
    ui->lcdTotal->setPalette(palette);
}


void BillDetails::applyCouponDiscount() {
    std::function<double(double)> coupon = [](double total) { return total * 0.95; };
    bill->applyDiscount(coupon);
    updateTotalDisplay();

    ui->labelDiscountStatus->setText("A 5% coupon discount has been applied.");
}

void BillDetails::applyPartyDiscount() {
    std::function<double(double)> party = [](double total) { return total * 0.9; };
    bill->applyDiscount(party);
    updateTotalDisplay();
    ui->labelDiscountStatus->setText("A 10% party discount has been applied.");
}

void BillDetails::applySeasonalDiscount() {
    std::function<double(double)> seasonal = [](double total) { return total * 0.85; };
    bill->applyDiscount(seasonal);
    updateTotalDisplay();
    ui->labelDiscountStatus->setText("A 15% seassonal discount has been applied.");
}

void BillDetails::updateTotalDisplay() {
    double total = bill->calculateTotal();
    ui->lcdTotal->display(total);  // Update the display with the new total

    // Print the total to the standard output
    std::cout << "Current Bill Total: $" << total << std::endl;
}


void BillDetails::makePayment() {
    // Process the payment and perhaps close the window or show a confirmation
    QMessageBox::information(this, "Payment Confirmation", "Your Payment was successful");
}

BillDetails::~BillDetails()
{
    delete ui;
    delete bill;  // Clean up the bill object
}
