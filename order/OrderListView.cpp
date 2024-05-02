#include "OrderListView.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QContextMenuEvent>
#include <QMenu>
#include <QDebug>
#include <QPushButton>

OrderListView::OrderListView(QWidget *parent) : QMainWindow(parent), listView(new QListView(this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel(tr("Order Management"), this);
    layout->addWidget(label);

    Order *order = new Order(); // Assuming you have an appropriate constructor
    model = new OrderListModel(order, this);
    listView->setModel(model);

    QPushButton *addButton = new QPushButton(tr("Add Order"), this);
    connect(addButton, &QPushButton::clicked, this, &OrderListView::onAddOrderClicked);
    layout->addWidget(addButton);

    layout->addWidget(listView);
    setLayout(layout);
}

void OrderListView::setOrder(Order *order)
{
    if (!order)
        return;
    OrderListModel *model = new OrderListModel(order, this);
    listView->setModel(model);
}

void OrderListView::contextMenuEvent(QContextMenuEvent *event)
{
    QModelIndex index = listView->indexAt(event->pos());
    if (index.isValid())
    {
        QMenu menu(this);
        QAction *deleteAction = menu.addAction("Delete Order");
        QAction *editAction = menu.addAction("Edit Order");
        QAction *selectedAction = menu.exec(mapToGlobal(event->pos()));
        QString orderID = index.data(OrderListModel::IdRole).toString();
        if (selectedAction == deleteAction)
        {
            emit orderDeleted(orderID);
        }
        else if (selectedAction == editAction)
        {
            emit editOrderRequested(orderID);
        }
    }
}

void OrderListView::onAddOrderClicked()
{
    emit addOrderRequested();
}