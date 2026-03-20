#include "CopperOre.hpp"

CopperOre::CopperOre() {

}

bool CopperOre::BreakableBy(Pickaxe pickaxe) {
    switch (pickaxe.GetPickaxeType()) {
        case PickaxeType::Stone:
        case PickaxeType::Iron:
        case PickaxeType::Diamond:
            return true;
        default:
            return false;
    }
}
std::shared_ptr<Ingot> CopperOre::Smelt() {
    return std::make_shared<Ingot>(Material::Copper);
}
