#include "GoldOre.hpp"

 GoldOre::GoldOre() {

}

bool GoldOre::BreakableBy(Pickaxe pickaxe) {
     switch (pickaxe.GetPickaxeType()) {
         case PickaxeType::Iron:
         case PickaxeType::Diamond:
             return true;
         default:
             return false;
     }
 }
std::shared_ptr<Ingot> GoldOre::Smelt() {
     return std::make_shared<Ingot>(Material::Gold);
 }