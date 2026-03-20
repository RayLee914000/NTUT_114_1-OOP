#include "Pickaxe/StonePickaxe.hpp"
#include <stdexcept>

 StonePickaxe::StonePickaxe(): Pickaxe(PickaxeType::Stone, Durability::StoneDurability) {

}
Product StonePickaxe::Mining(std::shared_ptr<Ore> &ore) {
     if (ore == nullptr) throw std::invalid_argument("");
     if (GetDurability() < ore->GetDurabilityCost()) throw std::invalid_argument("");
     if (ore->GetProduct() == Product::Obsidian)
         throw std::invalid_argument("");
     durability -= ore -> GetDurabilityCost();
     Product p = ore -> GetProduct();
     ore = nullptr;
     switch (p) {
         case Product::Coal:
            return Product::Coal;
         case Product::Iron:
            return Product::Iron;
         default:
             return Product::None;
     }
 }

