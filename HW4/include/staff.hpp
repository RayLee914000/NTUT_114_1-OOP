#ifndef STAFF_HPP
#define STAFF_HPP

#include "person.hpp"
#include <string>
#include "staff_level.hpp"
#include "staff_no.hpp"
#include "title.hpp"

class Staff : public Person {
private:
    StaffNo staffNo;
    StaffLevel level;

public:
    Staff(std::string name, Title title, std::string phone, int ext, StaffNo staffNo, StaffLevel level);
    StaffNo GetStaffNo();
    StaffLevel GetStaffLevel();
    int GetBasicSalary();
    int GetTotalSalary();
    virtual int GetBonus();
};

#endif