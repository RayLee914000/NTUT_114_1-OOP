#include "Pickaxe/GoldPickaxe.hpp"
#include <stdexcept>

 GoldPickaxe::GoldPickaxe(): Pickaxe(PickaxeType::Gold, Durability::GoldDurability) {

}
Product GoldPickaxe::Mining(std::shared_ptr<Ore> &ore) {
     if (ore == nullptr) throw std::invalid_argument("");
     if (GetDurability() < ore->GetDurabilityCost()) throw std::invalid_argument("");
     if (ore->GetProduct() == Product::Obsidian)
         throw std::invalid_argument("");
     durability -= ore -> GetDurabilityCost();
     Product p = ore -> GetProduct();
     ore = nullptr;
     if (p == Product::Coal) {
         return Product::Coal;
     }
     return Product::None;
 }

