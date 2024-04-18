#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QtCore/QString>

enum class Role{
    Admin = 1,
    StaffMember = 2,
    Accountant = 3
};

class Constants{
public:
    inline static const QString USER_FILE = "/Users/vijithagunta/Vijitha Masters Work/MSSE Sem2/cmpe202/restaurant-billing-system-qt/db/users.csv";
    inline static const QString EDIT_SVG = ":/edit.svg";
    inline static const QString DELETE_SVG = ":/delete.svg";

    inline static const qint16 USER_ID_COLUMN_INDEX = 0;
    inline static const qint16 USERNAME_COLUMN_INDEX = 1;
    inline static const qint16 PASSWORD_COLUMN_INDEX = 2;
    inline static const qint16 ROLE_COLUMN_INDEX = 3;
    inline static const qint16 ACTIONS_COLUMN_INDEX = 4;

    inline static const QString enumToString(Role role){
        switch (role) {
        case Role::Admin:
            return "Admin";
        case Role::Accountant:
            return "Accountant";
        case Role::StaffMember:
            return "Staff Member";
        default:
            return "";
        }
    }

    inline static const int indexToEnumValue(int selectedIndex){
        switch (selectedIndex) {
        case 0:
            return static_cast<int>(Role::Admin);
        case 1:
            return static_cast<int>(Role::StaffMember);
        case 2:
            return static_cast<int>(Role::Accountant);
        default:
            return -1;
        }
    }
};

#endif // CONSTANTS_H
