#include "Pickaxe/DiamondPickaxe.hpp"
#include <stdexcept>
 DiamondPickaxe::DiamondPickaxe(): Pickaxe(PickaxeType::Diamond, Durability::DiamondDurability) {

}
Product DiamondPickaxe::Mining(std::shared_ptr<Ore> &ore) {
     if (ore == nullptr) throw std::invalid_argument("");
     if (GetDurability() < ore->GetDurabilityCost()) throw std::invalid_argument("");
     durability -= ore -> GetDurabilityCost();
     Product p = ore -> GetProduct();
     ore = nullptr;
     return p;
 }

