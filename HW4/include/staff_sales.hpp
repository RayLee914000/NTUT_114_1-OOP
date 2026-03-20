#ifndef SALES_HPP
#define SALES_HPP

#include <string>
#include "staff_level.hpp"
#include "staff.hpp"

class StaffSales final:public Staff {
private:
    int totalSales;
    int count;
public:
    StaffSales(std::string name, std::string phone, int ext, StaffLevel level);
    void ApplyBonus(int totalSales, int count);
    int GetBonus();
};

#endif