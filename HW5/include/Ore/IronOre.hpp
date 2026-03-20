#ifndef IRONORE_HPP
#define IRONORE_HPP

#include "SmeltableOre.hpp"

class IronOre : public SmeltableOre{
public:
    explicit IronOre();

    float GetBreakExp() override;

    float GetSmeltExp() override;
};

#endif
