#ifndef BILLDETAILS_H
#define BILLDETAILS_H

#include <QMainWindow>
#include "../order/models/Order.h"
#include "../order/OrderTableAdapter.h"

namespace Ui {
class BillDetails;
}

class BillDetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit BillDetails(Order* order, QWidget *parent = nullptr);
    ~BillDetails();

    void applyCouponDiscount();  // Method to apply coupon discount
    void applyPartyDiscount();   // Method to apply party discount
    void applySeasonalDiscount();// Method to apply seasonal discount
    void makePayment();          // Method to process payment
private:
    Ui::BillDetails *ui;
    Order* order;
    OrderTableAdapter* adapter;
};

#endif // BILLDETAILS_H
