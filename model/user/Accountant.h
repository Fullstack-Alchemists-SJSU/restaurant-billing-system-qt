#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H

#include "User.h"

class Accountant : public User{
public:
    Accountant(){
        this->role = Role::Accountant;
    }
};

#endif // ACCOUNTANT_H
