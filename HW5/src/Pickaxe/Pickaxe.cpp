#include "Pickaxe/Pickaxe.hpp"

Pickaxe::Pickaxe(PickaxeType pickaxeType, int durability) {
    this -> pickaxeType = pickaxeType;
    this -> durability = durability;
}

Pickaxe::~Pickaxe() {

}

PickaxeType Pickaxe::GetPickaxeType() const {
    return pickaxeType;
}

int Pickaxe::GetDurability() const {
    return durability;
}

Product Pickaxe::Mining(std::shared_ptr<Ore> &ore) {

}
