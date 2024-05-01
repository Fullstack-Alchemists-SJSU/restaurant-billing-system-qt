#ifndef ORDERLISTVIEW_H
#define ORDERLISTVIEW_H

#include <QWidget>
#include <QListView>
#include "OrderListModel.h"
#include "Order.h"

class OrderListView : public QWidget
{
    Q_OBJECT
public:
    explicit OrderListView(QWidget *parent = nullptr);
    void setOrder(Order *order);
    void contextMenuEvent(QContextMenuEvent *event);
    void onAddOrderClicked();

private:
    QListView *listView;
    OrderListModel *model;

signals:
    void orderDeleted(const QString &orderID);
    void addOrderRequested();
    void editOrderRequested(const QString &orderID);
};

#endif // ORDERLISTVIEW_H
