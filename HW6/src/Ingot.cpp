#include "Ingot.hpp"

 Ingot::Ingot(Material material) {
    this -> material = material;
}
Material Ingot::GetMaterial() {
    return material;
}
