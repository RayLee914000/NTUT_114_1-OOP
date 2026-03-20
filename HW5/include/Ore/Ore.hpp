#ifndef ORE_HPP
#define ORE_HPP

#include "Product.hpp"
#include "BreakExp.hpp"
#include "DurabilityCost.hpp"


class Ore {
private:
    Product product;
    int durabilityCost;
public:
    explicit Ore(Product product, int durabilityCost);
    ~Ore();

    [[nodiscard]] Product GetProduct() const;
    [[nodiscard]] int GetDurabilityCost() const;

    virtual float GetBreakExp();
};

#endif
