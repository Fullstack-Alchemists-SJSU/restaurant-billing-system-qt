#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"
class Admin : public User{
public:
    Admin(){
        this->role = Role::Admin;
    }
};

#endif // ADMIN_H
