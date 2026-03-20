#include "Ore/CoalOre.hpp"

 CoalOre::CoalOre() : Ore(Product::Coal, 1){

}
float CoalOre::GetBreakExp() {
     return 2;
 }

