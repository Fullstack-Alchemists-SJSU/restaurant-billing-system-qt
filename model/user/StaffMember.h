#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H

#include "User.h"

class StaffMember : public User{
public:
    StaffMember(){
        this->role = Role::StaffMember;
    }
};

#endif // STAFFMEMBER_H
