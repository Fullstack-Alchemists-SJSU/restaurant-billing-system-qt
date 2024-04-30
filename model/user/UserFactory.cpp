#include "UserFactory.h"

User* UserFactory::build(std::unique_ptr<User> user){

    User *factoryUser;

    if (user->getRole() == Role::Admin)
    {
        factoryUser = new Admin();
    }
    else if (user->getRole() == Role::StaffMember)
    {
        factoryUser = new StaffMember();
    }else if (user->getRole() == Role::Accountant)
    {
        factoryUser = new Accountant();
    }

    factoryUser->setUserId(user->getUserId());
    factoryUser->setUsername(user->getUsername());
    factoryUser->setPassword(user->getPassword());

    return factoryUser;
}

User* UserFactory::build(qint16 userId, QString username, QString password, Role role){
    User* factoryUser;

    if (role == Role::Admin)
    {
        factoryUser = new Admin();
    }
    else if (role == Role::StaffMember)
    {
        factoryUser = new StaffMember();
    }else if (role == Role::Accountant)
    {
        factoryUser = new Accountant();
    }

    factoryUser->setUserId(userId);
    factoryUser->setUsername(username);
    factoryUser->setPassword(password);

    return factoryUser;
}
