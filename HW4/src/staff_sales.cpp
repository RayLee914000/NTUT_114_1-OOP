#include "staff_sales.hpp"
#include "title.hpp"

StaffSales::StaffSales(std::string name, std::string phone, int ext, StaffLevel level):
Staff(name, Title::STAFF_SALES, phone, ext, StaffNo::S, level){

}

void StaffSales::ApplyBonus(int totalSales, int count){
    this->totalSales = totalSales;
    this->count = count;
}
int StaffSales::GetBonus() {
    if (count > 0 && count <= 10) {
        totalSales *= 0.1;
    }else if (count > 10 && count <= 20) {
        totalSales *= 0.15;
    }else {
        totalSales *= 0.2;
    }
    return totalSales;
}