#ifndef ARMOR_HPP
#define ARMOR_HPP

#include "IEnchantable.hpp"

enum class ArmorType {
    Iron,
    Gold,
    Diamond,
};

class Armor final: public IEnchantable{
public:
    ArmorType armorType;

    Armor(ArmorType armorType);
    ArmorType GetArmorType();
    Enchantment GetEnchantment();

    void ApplyEnchantment(const Enchantment e) override;
};

#endif
