#include "staff.hpp"

#include <vector>

#include "staff_level.hpp"
#include "staff_no.hpp"

Staff::Staff(std::string name, Title title, std::string phone, int ext, StaffNo staffNo, StaffLevel level) : Person(name, title, phone, ext) {
    this -> staffNo = staffNo;
    this -> level = level;
}

StaffNo Staff::GetStaffNo(){
    return staffNo;
}

StaffLevel Staff::GetStaffLevel(){
    return level;
}

int Staff::GetBasicSalary(){
    double array[4][3] = {
        {120000, 120000*1.68, 120000 * 2.32},
        {73000,73000*1.17,73000*1.32},
        {93000,93000 * 1.43, 93000 * 1.82},
        {55000, 55000 * 1.12, 55000 * 1.24}};
    int x = 0, y = 0;
    switch (staffNo) {
        case StaffNo::M:
            x = 0;
            break;
        case StaffNo::S:
            x = 1;
            break;
        case StaffNo::E:
            x = 2;
            break;
        case StaffNo::N:
            x = 3;
            break;
    }
    switch (level) {
        case StaffLevel::L1:
            y = 0;
            break;
        case StaffLevel::L2:
            y = 1;
            break;
        case StaffLevel::L3:
            y = 2;
            break;
    }
    return (int)array[x][y] * 16;
}

int Staff::GetBonus(){
    int array [2][3] = {
        {60000, 73000, 94000},
        {56000, 64000, 83000}
    };
    int x = 0, y = 0;
    switch (staffNo) {
    case StaffNo::M:
        x = 0;
        break;
    case StaffNo::E:
        x = 1;
        break;
    default:
        return 0;
    }
    switch (level) {
    case StaffLevel::L1:
        y = 0;
        break;
    case StaffLevel::L2:
        y = 1;
        break;
    case StaffLevel::L3:
        y = 2;
        break;
    }
    return array[x][y];
}

int Staff::GetTotalSalary(){
    return GetBasicSalary() + GetBonus();
}