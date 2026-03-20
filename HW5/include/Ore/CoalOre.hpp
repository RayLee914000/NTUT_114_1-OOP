#ifndef COALORE_HPP
#define COALORE_HPP

#include "Ore.hpp"
#include "Product.hpp"

class CoalOre : public Ore{
public:
    explicit CoalOre();

    float GetBreakExp() override;
};

#endif
