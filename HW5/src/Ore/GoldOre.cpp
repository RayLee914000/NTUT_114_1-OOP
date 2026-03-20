#include "Ore/GoldOre.hpp"

 GoldOre::GoldOre():SmeltableOre(Product::Gold, 5) {

 }

float GoldOre::GetBreakExp() {
     return 0;
 }

float GoldOre::GetSmeltExp() {
     return 1;
 }

