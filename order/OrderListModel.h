#ifndef ORDERLISTMODEL_H
#define ORDERLISTMODEL_H

#include <QAbstractListModel>
#include "./models/Order.h"

class OrderListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit OrderListModel(Order *order, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    enum OrderItemRoles
    {
        IdRole = Qt::UserRole + 1,
        TotalPriceRole,
        StatusRole
    };
    Q_ENUM(OrderItemRoles)

private:
    Order *order;
};

#endif // ORDERLISTMODEL_H
