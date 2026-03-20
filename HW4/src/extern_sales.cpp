#include "extern_sales.hpp"
#include "vendor.hpp"

ExternSales::ExternSales(std::string name, std::string phone, int ext)
:Vendor(name, Title::EXTERN_SALES, phone, ext){

}

void ExternSales::ApplyBonus(int totalSales, int count){
    this->totalSales = totalSales;
    this->count = count;
}
int ExternSales::GetBonus() {
    if (count > 0 && count <= 10) {
        totalSales *= 0.1;
    }else if (count > 10 && count <= 20) {
        totalSales *= 0.15;
    }else {
        totalSales *= 0.2;
    }
    return totalSales;
}