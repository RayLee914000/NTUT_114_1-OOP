#ifndef DIAMOND_ORE_HPP
#define DIAMOND_ORE_HPP

#include "IConsumable.hpp"
#include "ISmeltable.hpp"
#include "Ore.hpp"

class DiamondOre final : public Ore{
public:
    DiamondOre();
    bool BreakableBy(Pickaxe pickaxe) override;
};

#endif
