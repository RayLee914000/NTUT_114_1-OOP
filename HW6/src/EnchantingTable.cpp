#include "EnchantingTable.hpp"
#include <stdexcept>

 EnchantingTable::EnchantingTable() {

}

void EnchantingTable::SetEnchantItem(std::shared_ptr<IEnchantable> enchantable) {
    this -> enchant = enchantable;
 }

void EnchantingTable::SetConsumeItem(std::shared_ptr<IConsumable> consumable) {
     if (consumable == nullptr)
         return;
     if (consumable -> GetMaterial() != Material::LapisLazuli)
         throw std::invalid_argument("");
     this -> consume = consumable;
}

void EnchantingTable::Enchant(Enchantment e) {
     if (enchant == nullptr || consume == nullptr || output != nullptr)
         throw std::invalid_argument("");

     enchant -> ApplyEnchantment(e);
     output = enchant;

     enchant = nullptr;
     consume = nullptr;
}

std::shared_ptr<IEnchantable> EnchantingTable::GetOutput() {
     if (output == nullptr)
         throw std::invalid_argument("");
    return output;
}


