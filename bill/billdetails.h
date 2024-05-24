#ifndef BILLDETAILS_H
#define BILLDETAILS_H

#include <QMainWindow>
#include <memory>
#include <QLabel>
#include "../order/models/Order.h"
#include "../order/OrderTableAdapter.h"
#include "bill.h"

namespace Ui {
class BillDetails;
}

class BillDetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit BillDetails(Order* order, QWidget *parent = nullptr);
    ~BillDetails();

    void applyCouponDiscount();
    void applyPartyDiscount();
    void applySeasonalDiscount();
    void makePayment();
    void updateTotalDisplay();

private:
    Ui::BillDetails *ui;
    Order* order;
    OrderTableAdapter* adapter;
    std::shared_ptr<BillInterface> bill;
    QLabel *labelDiscountStatus;
};

#endif // BILLDETAILS_H
