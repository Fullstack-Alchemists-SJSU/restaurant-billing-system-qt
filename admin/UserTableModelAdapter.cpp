#include "UserTableModelAdapter.h"

#define NUM_TABLE_COLUMNS 5  // ID, Username, Password, Role, Actions

UserTableModelAdapter::UserTableModelAdapter(QObject *parent)
        : QAbstractTableModel(parent) {}

void UserTableModelAdapter::setUsers(const QList<User*>& users) {
    beginResetModel();
    this->users = users;
    endResetModel();
}

int UserTableModelAdapter::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return users.count();
}

int UserTableModelAdapter::columnCount(const QModelIndex &parent) const{
    Q_UNUSED(parent);
    return NUM_TABLE_COLUMNS;
}

QVariant UserTableModelAdapter::data(const QModelIndex &index, int role) const{
    if (!index.isValid() || index.row() >= users.count() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        const User* user = users.at(index.row());
        switch (index.column()) {
        case Constants::USER_ID_COLUMN_INDEX:
            return user->getUserId();
        case Constants::USERNAME_COLUMN_INDEX:
            return user->getUsername();
        case Constants::PASSWORD_COLUMN_INDEX:
            return user->getPassword();
        case Constants::ROLE_COLUMN_INDEX:
            return User::enumToString(user->getRole());
        case 4:
            return "";
        default:
            return QVariant();
        }
    }
    return QVariant();
}

QVariant UserTableModelAdapter::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case Constants::USER_ID_COLUMN_INDEX:
            return "User ID";
        case Constants::USERNAME_COLUMN_INDEX:
            return "Username";
        case Constants::PASSWORD_COLUMN_INDEX:
            return "Password";
        case Constants::ROLE_COLUMN_INDEX:
            return "Role";
        case 4:
            return "Actions";
        default:
            return QVariant();
        }
    }
    return QVariant();
}
