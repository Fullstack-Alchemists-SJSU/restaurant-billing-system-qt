#ifndef ORDERWINDOW_H
#define ORDERWINDOW_H

#include <QMainWindow>
#include "OrderListView.h"
#include "Order.h"

class OrderWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit OrderWindow(Order* order, QWidget *parent = nullptr);
private:
    OrderListView* orderListView;
};

#endif // ORDERWINDOW_H
