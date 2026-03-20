#include "LapisLazuliOre.hpp"

 LapisLazuliOre::LapisLazuliOre() {

}
bool LapisLazuliOre::BreakableBy(Pickaxe pickaxe) {
     switch (pickaxe.GetPickaxeType()) {
         case PickaxeType::Stone:
         case PickaxeType::Iron:
         case PickaxeType::Diamond:
             return true;
         default:
             return false;
     }
 }

