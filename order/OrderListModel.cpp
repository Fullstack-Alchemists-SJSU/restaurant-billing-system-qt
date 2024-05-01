#include "OrderListModel.h"

OrderListModel::OrderListModel(Order *order, QObject *parent)
    : QAbstractListModel(parent), order(order) {}

int OrderListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return order->getItems().size();
}

QVariant OrderListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= rowCount())
        return QVariant();

    const OrderItem &item = order->getItems().at(index.row());

    switch (role)
    {
    case IdRole:
        return QVariant(order->getOrderID());
    case TotalPriceRole:
        return QVariant(order->getTotalPrice());
    case StatusRole:
        return QVariant(QString::fromStdString(order->getStatus()));
    default:
        return QVariant();
    }
}
