#include "Ore/Ore.hpp"
#include <stdexcept>


Ore::Ore(Product product, int durabilityCost) {
    if (Product::None == product)
        throw std::invalid_argument("");
    this -> product = product;
    this -> durabilityCost = durabilityCost;
}

Ore::~Ore() {

}

Product Ore::GetProduct() const{
    return product;
}

int Ore::GetDurabilityCost() const {
    return durabilityCost;
}

float Ore::GetBreakExp() {

}