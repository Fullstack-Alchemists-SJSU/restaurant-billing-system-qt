#ifndef ORDERLISTVIEW_H
#define ORDERLISTVIEW_H

#include <QMainWindow>
#include <QWidget>
#include <QListView>
#include "OrderListModel.h"
#include "./models/Order.h"

class OrderListView : public QMainWindow
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
