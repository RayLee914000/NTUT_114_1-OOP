#ifndef ENCHANTING_TABLE_HPP
#define ENCHANTING_TABLE_HPP

#include <memory>
#include "IEnchantable.hpp"
#include "IConsumable.hpp"
#include "Enchantment.hpp"

class EnchantingTable{
private:
    std::shared_ptr<IEnchantable> enchant;
    std::shared_ptr<IConsumable> consume;
    std::shared_ptr<IEnchantable> output;
public:
    EnchantingTable();

    void SetEnchantItem(std::shared_ptr<IEnchantable> enchantable);
    void SetConsumeItem(std::shared_ptr<IConsumable> consumable);
    void Enchant(Enchantment e);
    std::shared_ptr<IEnchantable> GetOutput();
};

#endif