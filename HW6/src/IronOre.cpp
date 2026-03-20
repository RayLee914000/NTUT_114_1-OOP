#include "IronOre.hpp"

IronOre::IronOre() : Ore() {

}

bool IronOre::BreakableBy(Pickaxe pickaxe) {
    switch (pickaxe.GetPickaxeType()) {
        case PickaxeType::Stone:
        case PickaxeType::Iron:
        case PickaxeType::Diamond:
            return true;
        default:
        return false;
    }
}
std::shared_ptr<Ingot> IronOre::Smelt() {
    return std::make_shared<Ingot>(Material::Iron);
}