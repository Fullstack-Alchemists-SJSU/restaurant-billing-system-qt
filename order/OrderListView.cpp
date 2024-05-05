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
    model.reset(new OrderListModel(order, this)); // Automatically deletes the old model
    listView->setModel(model.get());
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
        QString orderID = index.data(OrderListModel::NameRole).toString();
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
