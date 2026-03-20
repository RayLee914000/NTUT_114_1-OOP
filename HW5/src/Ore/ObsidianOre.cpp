#include "Ore/ObsidianOre.hpp"

 ObsidianOre::ObsidianOre() : Ore(Product::Obsidian, 40) {

}
float ObsidianOre::GetBreakExp() {
     return 8;
 }

