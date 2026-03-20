#include "Pickaxe/WoodenPickaxe.hpp"
#include <stdexcept>

 WoodenPickaxe::WoodenPickaxe() : Pickaxe(PickaxeType::Wooden, Durability::WoodenDurability) {

}
Product WoodenPickaxe::Mining(std::shared_ptr<Ore> &ore) {
     if (ore == nullptr) throw std::invalid_argument("");
     if (GetDurability() < ore->GetDurabilityCost()) throw std::invalid_argument("");
     if (ore->GetProduct() == Product::Obsidian)
         throw std::invalid_argument("");
     durability -= ore -> GetDurabilityCost();
     if (ore -> GetProduct() == Product::Coal) {
         ore = nullptr;
         return Product::Coal;
     }
     ore = nullptr;
     return Product::None;
 }