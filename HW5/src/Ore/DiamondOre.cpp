#include "Ore/DiamondOre.hpp"

 DiamondOre::DiamondOre() :Ore(Product::Diamond, 10) {

}

float DiamondOre::GetBreakExp() {
     return 4;
 }
