#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QtCore/QString>

class Constants{
public:
    inline static const QString USER_FILE = "/Users/vijithagunta/Vijitha Masters Work/MSSE Sem2/cmpe202/restaurant-billing-system-qt/db/users.csv";
    inline static const QString ORDER_FILE = "/Users/vijithagunta/Vijitha Masters Work/MSSE Sem2/cmpe202/restaurant-billing-system-qt/db/orders.csv";
    inline static const QString MENU_FILE = "/Users/vijithagunta/Vijitha Masters Work/MSSE Sem2/cmpe202/restaurant-billing-system-qt/db/menuitems.csv";
    inline static const QString EDIT_SVG = ":/edit.svg";
    inline static const QString DELETE_SVG = ":/delete.svg";

    inline static const qint16 USER_ID_COLUMN_INDEX = 0;
    inline static const qint16 USERNAME_COLUMN_INDEX = 1;
    inline static const qint16 PASSWORD_COLUMN_INDEX = 2;
    inline static const qint16 ROLE_COLUMN_INDEX = 3;
    inline static const qint16 ACTIONS_COLUMN_INDEX = 4;
};

#endif // CONSTANTS_H
