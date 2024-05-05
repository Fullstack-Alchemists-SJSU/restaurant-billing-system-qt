#include "OrderListModel.h"

OrderListModel::OrderListModel(Order *order, QObject *parent)
    : QAbstractListModel(parent), order(order) {}

int OrderListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;                                   // Ensures we are dealing with a flat list
    return static_cast<int>(order->getItemCount()); // Use the new getItemCount method
}

QVariant OrderListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= rowCount())
        return QVariant();

    const OrderItem &item = order->getItemAt(static_cast<size_t>(index.row())); // Use the new getItemAt method

    switch (role)
    {
    case NameRole:
        return QVariant(QString::fromStdString(item.getMenuItem()->getName()));
    case QuantityRole:
        return QVariant(item.getQuantity());
    case UnitPriceRole:
        return QVariant(item.getMenuItem()->getPrice());
    default:
        return QVariant();
    }
}
