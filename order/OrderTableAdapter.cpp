#include "OrderTableAdapter.h"

OrderTableAdapter::OrderTableAdapter(QObject *parent)
    : QAbstractTableModel(parent) {
}

void OrderTableAdapter::setOrderItems(std::vector<OrderItem*> items) {
    beginResetModel();
    orderItems = items;
    endResetModel();
}

int OrderTableAdapter::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return orderItems.size();
}

int OrderTableAdapter::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 3;  // Name, Price and Quantity
}

QVariant OrderTableAdapter::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    const OrderItem* item = orderItems.at(index.row());
    switch (index.column()) {
    case 0: return QString::fromStdString(item->getMenuItemName());
    case 1: return item->getMenuItem()->getPrice();
    case 2: return item->getQuantity();
    default: return QVariant();
    }
}

QVariant OrderTableAdapter::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return QVariant();

    switch (section) {
    case 0: return QString("Menu Item");
    case 1: return QString("Price");
    case 2: return QString("Quantity");
    default: return QVariant();
    }
}
