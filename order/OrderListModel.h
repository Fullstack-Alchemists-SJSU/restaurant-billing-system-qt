#ifndef ORDERLISTMODEL_H
#define ORDERLISTMODEL_H

#include <QAbstractListModel>
#include "Order.h" // Adjust include path as necessary

class OrderListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit OrderListModel(Order *order, QObject *parent = nullptr);
    ~OrderListModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    enum OrderItemRoles
    {
        NameRole = Qt::UserRole + 1,
        QuantityRole,
        UnitPriceRole
    };
    Q_ENUM(OrderItemRoles)

private:
    Order *order; // Pointer to the order
    QListView *listView;
    std::unique_ptr<OrderListModel> model;
};

#endif // ORDERLISTMODEL_H
