#include "CraftingTable.hpp"

#include <stdexcept>
#include <utility>

 CraftingTable::CraftingTable() {
     craftableItem = nullptr;
     materialItem = nullptr;
     output = nullptr;
}
void CraftingTable::Craft() {
     if (craftableItem == nullptr || output != nullptr) throw std::invalid_argument("");

     bool hasStick = false;
     if (materialItem != nullptr) {
         if (materialItem -> GetMaterial() == Material::Stick) {
             hasStick = true;
         }
     }

     Material mat = craftableItem -> GetMaterial();
     if (hasStick) {
         PickaxeType pickaxeType;
         switch (mat) {
             case Material::Iron:
                 pickaxeType = PickaxeType::Iron;
                 break;
             case Material::Gold:
                 pickaxeType = PickaxeType::Gold;
                 break;
             case Material::Diamond:
                 pickaxeType = PickaxeType::Diamond;
                 break;
         default:
                throw std::invalid_argument("");
         }
         output = std::make_shared<Pickaxe>(pickaxeType);
     }else {
         ArmorType type;
         switch (mat) {
             case Material::Iron:
                 type = ArmorType::Iron;
                 break;
             case Material::Gold:
                 type = ArmorType::Gold;
                 break;
             case Material::Diamond:
                 type = ArmorType::Diamond;
                 break;
             default:
                throw std::invalid_argument("");
         }
         output = std::make_shared<Armor>(type);
     }

     craftableItem = nullptr;
     materialItem = nullptr;
 }

void CraftingTable::SetCraftInput(std::shared_ptr<IConsumable> craftableItem) {
     switch (craftableItem -> GetMaterial()) {
        case Material::Copper:
        case Material::LapisLazuli:
        case Material::Stick:
         throw std::invalid_argument("");
        default:
            break;
     }
    this -> craftableItem = craftableItem;
}

void CraftingTable::SetMaterialInput(std::shared_ptr<IConsumable> materialItem) {
     if (materialItem -> GetMaterial() != Material::Stick) throw std::invalid_argument("");
     this -> materialItem = materialItem;
}

std::shared_ptr<IEnchantable> CraftingTable::GetOutput() {
     if (output == nullptr) throw std::invalid_argument("");
    return output;
}