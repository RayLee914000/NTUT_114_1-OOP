#include "Snack.hpp"

Snack::Snack(std::string snackName){
    name = snackName;
    amount = 1;
}

Snack::Snack(std::string snackName, int snackAmount){
    name = snackName;
    amount = snackAmount;
}

std::string Snack::getName() const{
    return name;
}

int Snack::getAmount() const{
    return amount;
}

void Snack::setAmount(int snackAmount){
    amount = snackAmount;
}