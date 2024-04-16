#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "FileManager.h"
#include "../model/user/User.h"
#include "../model/user/UserFactory.h"

class UserManager : FileManager{

public:
    UserManager();
    QList<User*> getAllUsers();
    User* getUser(int id);
    void addUser(User* user);
    void updateUser(User* user);
    void deleteUser(User* user);
    int getNextUserId();
};

#endif // USERMANAGER_H
