#include "Furnace.hpp"
#include <stdexcept>

 Furnace::Furnace() {
     this -> input = nullptr;
     this -> output = nullptr;
}

void Furnace::Smelt() {
     if (input == nullptr || output != nullptr) throw std::invalid_argument("");
     output = input -> Smelt();
     input = nullptr;
}

void Furnace::SetInput(std::shared_ptr<ISmeltable> input) {
    this -> input = input;
}

std::shared_ptr<Ingot> Furnace::GetOutput() {
     if (output == nullptr) throw std::invalid_argument("");
    return output;
}


