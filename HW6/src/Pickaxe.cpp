#include "Pickaxe.hpp"

 Pickaxe::Pickaxe(PickaxeType pickaxeType) {
     this -> pickaxeType = pickaxeType;
     this -> enchantment = Enchantment::NaN;
}

PickaxeType Pickaxe::GetPickaxeType() {
    return pickaxeType;
}

Enchantment Pickaxe::GetEnchantment() {
    return enchantment;
}

void Pickaxe::ApplyEnchantment(const Enchantment e) {
    this -> enchantment = e;
}

