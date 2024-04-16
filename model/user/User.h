#ifndef USER_H
#define USER_H

#include <QtCore>
#include "../util/Constants.h"

enum class Role{
    Admin = 1,
    StaffMember = 2,
    Accountant = 3
};

class User{
protected:
    User(){

    }

    qint16 userId;
    QString username, password;
    Role role;

public:
    virtual ~User() {}

    virtual void setUserId(qint16 newUserId){
        this->userId = newUserId;
    };

    virtual int getUserId() const{
        return this->userId;
    };

    virtual void setUsername(QString newUsername){
        this->username = newUsername;
    };

    virtual QString getUsername() const{
        return this->username;
    };

    virtual void setPassword(QString newPassword){
        this->password = newPassword;
    };

    virtual QString getPassword() const{
        return this->password;
    };

    virtual void setRole(Role role){
        this->role = role;
    };

    virtual Role getRole() const{
        return this->role;
    };

    inline const bool compare(User* another){
        if(this->userId != another->userId){
            return false;
        }

        if(this->username != another->username){
            return false;
        }

        if(this->password != another->password){
            return false;
        }

        if(this->role != another->role){
            return false;
        }

        return true;
    }

    inline static const QStringList deserialize(User* user){
        QStringList userData;
        userData.insert(Constants::USER_ID_COLUMN_INDEX, QString::number(user->getUserId()));
        userData.insert(Constants::USERNAME_COLUMN_INDEX, user->getUsername());
        userData.insert(Constants::PASSWORD_COLUMN_INDEX, user->getPassword());
        userData.insert(Constants::ROLE_COLUMN_INDEX, QString::number(static_cast<int>(user->getRole())));

        return userData;
    }

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

    inline static const int comboIndexToEnumValue(int selectedIndex){
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

    inline static const Role intToEnumValue(int role){
        switch (role) {
        case 1:
            return Role::Admin;
        case 2:
            return Role::StaffMember;
        case 3:
            return Role::Accountant;
        default:
            return Role::StaffMember;
        }
    }
};

#endif // USER_H
