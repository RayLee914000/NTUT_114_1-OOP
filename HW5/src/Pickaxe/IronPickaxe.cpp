#include "Pickaxe/IronPickaxe.hpp"
#include <stdexcept>

 IronPickaxe::IronPickaxe() : Pickaxe(PickaxeType::Iron, Durability::IronDurability){

}
Product IronPickaxe::Mining(std::shared_ptr<Ore> &ore) {
     if (ore == nullptr) throw std::invalid_argument("");
     if (GetDurability() < ore->GetDurabilityCost()) throw std::invalid_argument("");

     durability -= ore -> GetDurabilityCost();
     Product p = ore -> GetProduct();
     ore = nullptr;
     if (p != Product::Obsidian) {
         return p;
     }
     return Product::None;
 }

