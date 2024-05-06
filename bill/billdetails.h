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

private:
    Ui::BillDetails *ui;
    Order* order;
    OrderTableAdapter* adapter;
};

#endif // BILLDETAILS_H
