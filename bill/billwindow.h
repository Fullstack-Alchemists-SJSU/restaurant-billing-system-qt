#ifndef BILLWINDOW_H
#define BILLWINDOW_H

#include <QMainWindow>
#include "../order/models/Order.h"
#include "../order/facade/OrderManagementFacade.h"

namespace Ui {
class BillWindow;
}

class BillWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BillWindow(QWidget *parent = nullptr);
    ~BillWindow();

private:
    Ui::BillWindow *ui;
    std::vector<Order *> orders;

    void populateOrders();
};

#endif // BILLWINDOW_H
