#include "Armor.hpp"

Armor::Armor(ArmorType armorType) {
     this -> armorType = armorType;
     this -> enchantment = Enchantment::NaN;
}

ArmorType Armor::GetArmorType() {
    return armorType;
}

Enchantment Armor::GetEnchantment() {
    return enchantment;
}

void Armor::ApplyEnchantment(const Enchantment e) {
    this -> enchantment = e;
}


