#ifndef USERFACTORY_H
#define USERFACTORY_H

#include "User.h"
#include "Admin.h"
#include "StaffMember.h"
#include "Accountant.h"

class UserFactory{
private:
    UserFactory();
public:
    static User* build(std::unique_ptr<User> user);
    static User* build(qint16 userid, QString username, QString password, Role role);
};

#endif // USERFACTORY_H
