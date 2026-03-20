#include "Ore/IronOre.hpp"

 IronOre::IronOre():SmeltableOre(Product::Iron, 3) {

 }

float IronOre::GetBreakExp() {
    return 0;
 }

float IronOre::GetSmeltExp() {
    return 0.7;
 }

