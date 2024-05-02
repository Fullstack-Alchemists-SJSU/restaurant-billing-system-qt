#ifndef ORDERDETAILS_H
#define ORDERDETAILS_H

#include <QMainWindow>
#include "models/Order.h"

namespace Ui {
class OrderDetails;
}

class OrderDetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrderDetails(Order* order, QWidget *parent = nullptr);
    ~OrderDetails();

private:
    Ui::OrderDetails *ui;
    Order* order;
};

#endif // ORDERDETAILS_H
