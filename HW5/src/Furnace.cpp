#include "Furnace.hpp"

#include <stdexcept>

 Furnace::Furnace() {
     product = Product::None;

}
Furnace::~Furnace() {

 }
std::vector<std::shared_ptr<Ore>> Furnace::PickupProduct() {
     product = Product::None;
     std::vector<std::shared_ptr<Ore>> s = products;
     products.clear();
     return s;
}

void Furnace::AddOre(std::shared_ptr<SmeltableOre> ore) {
     if (std::size(products) >= 64) throw std::invalid_argument("");
     if (ore -> GetProduct() != product && product != Product::None) throw std::invalid_argument("");
     product = ore -> GetProduct();
     products.push_back(std::static_pointer_cast<Ore>(ore));
}

void Furnace::AddAnyOre(std::shared_ptr<Ore> ore) {
    if (ore -> GetProduct() != Product::Iron && ore -> GetProduct() != Product::Gold) throw std::invalid_argument("");
     if (std::size(products) >= 64) throw std::invalid_argument("");
     if (ore -> GetProduct() != product && product != Product::None) throw std::invalid_argument("");
     product = ore -> GetProduct();
     products.push_back(ore);
}



