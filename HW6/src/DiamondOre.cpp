#include "DiamondOre.hpp"

 DiamondOre::DiamondOre() {

}
bool DiamondOre::BreakableBy(Pickaxe pickaxe) {
     switch (pickaxe.GetPickaxeType()) {
         case PickaxeType::Iron:
         case PickaxeType::Diamond:
             return true;
         default:
             return false;
     }
 }
