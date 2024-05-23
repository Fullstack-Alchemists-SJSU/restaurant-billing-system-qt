#include "billdetails.h"
#include "ui_billdetails.h"
#include <QDateTime>
#include <QMessageBox>
#include "CouponDiscountDecorator.h"
#include "PartyDiscountDecorator.h"
#include "SeasonalDiscountDecorator.h"
#include <iostream>

BillDetails::BillDetails(Order* order, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BillDetails)
    , order(order)
    , adapter(new OrderTableAdapter(this))
    , bill(std::make_shared<Bill>(1, order, QDateTime::currentDateTimeUtc().toString().toStdString()))  // Initialize bill here
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

    // Calculate initial total amount and display it
    std::static_pointer_cast<Bill>(bill)->generateBill();  // Use initialBill to call generateBill
    ui->lcdTotal->display(bill->getTotalAmount());  // Display the initial total amount

    QPalette palette = ui->lcdTotal->palette();
    palette.setColor(QPalette::WindowText, QColor(Qt::black));
    palette.setColor(palette.Dark, QColor(255, 0, 0));
    ui->lcdTotal->setPalette(palette);
}

void BillDetails::applyCouponDiscount() {
    bill = std::make_shared<CouponDiscountDecorator>(bill);
    updateTotalDisplay();
    ui->labelDiscountStatus->setText("A 5% coupon discount has been applied.");
}

void BillDetails::applyPartyDiscount() {
    bill = std::make_shared<PartyDiscountDecorator>(bill);
    updateTotalDisplay();
    ui->labelDiscountStatus->setText("A 10% party discount has been applied.");
}

void BillDetails::applySeasonalDiscount() {
    bill = std::make_shared<SeasonalDiscountDecorator>(bill);
    updateTotalDisplay();
    ui->labelDiscountStatus->setText("A 15% seasonal discount has been applied.");
}

void BillDetails::updateTotalDisplay() {
    double total = bill->getTotalAmount();
    ui->lcdTotal->display(total);  // Update the display with the new total

    std::cout << "Current Bill Total: $" << total << std::endl;
}

void BillDetails::makePayment() {
    QMessageBox::information(this, "Payment Confirmation", "Your Payment was successful");
}

BillDetails::~BillDetails() {
    delete ui;
}
