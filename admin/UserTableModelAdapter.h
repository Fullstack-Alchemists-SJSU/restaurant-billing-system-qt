#ifndef USERTABLEMODELADAPTER_H
#define USERTABLEMODELADAPTER_H

#include <QAbstractTableModel>
#include <QList>
#include "../util/Constants.h"
#include "../model/user/User.h"

class UserTableModelAdapter : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit UserTableModelAdapter(QObject *parent = nullptr);

    // Setters
    void setUsers(const QList<User*>& users);

    // Required overrides for QAbstractTableModel
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

private:
    QList<User*> users;
#endif // USERTABLEMODELADAPTER_H
