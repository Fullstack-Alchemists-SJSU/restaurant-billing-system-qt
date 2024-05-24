#ifndef ORDERTABLEADAPTER_H
#define ORDERTABLEADAPTER_H

#include <QAbstractTableModel>
#include <vector>
#include "./models/OrderItem.h"

class OrderTableAdapter : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit OrderTableAdapter(QObject *parent = nullptr);

    void setOrderItems(std::vector<OrderItem*> items);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

private:
    std::vector<OrderItem*> orderItems;
};
#endif // ORDERTABLEADAPTER_H
