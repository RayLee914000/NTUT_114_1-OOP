#ifndef CRAFTING_TABLE_HPP
#define CRAFTING_TABLE_HPP

#include <memory>

#include "Armor.hpp"
#include "IConsumable.hpp"
#include "Pickaxe.hpp"

class CraftingTable final {
public:
    std::shared_ptr<IConsumable> craftableItem;
    std::shared_ptr<IConsumable> materialItem;
    std::shared_ptr<IEnchantable> output;
    CraftingTable();
    void Craft();

    void SetCraftInput(std::shared_ptr<IConsumable> craftableItem);
    void SetMaterialInput(std::shared_ptr<IConsumable> materialItem);
    std::shared_ptr<IEnchantable> GetOutput();
};

#endif
