#include "Storage.hpp"
#include <stdexcept>
#include <algorithm>

Storage::Storage(StorageType storageType){
    type = storageType;
    capacity = 10;
    amount = 0;
}

Storage::Storage(StorageType storageType, int storageCapacity){
    type = storageType;
    capacity = storageCapacity;
    amount = 0;
}

void Storage::add(std::string snackName) {
    if (amount >= capacity) {
        throw std::invalid_argument("");
    }
    bool tf = true;
    for (int i = 0; i < snacks.size() && tf; i++) {
        if (snacks[i].getName() == snackName) {
            snacks[i].setAmount(snacks[i].getAmount() + 1);
            tf = false;
        }
    }
    if (tf) {
        snacks.push_back(Snack(snackName));
    }
    amount += 1;
}

void Storage::add(std::string snackName, int snackAmount) {
    if (amount + snackAmount > capacity) {
        throw std::invalid_argument("");
    }
    bool tf = true;
    for (int i = 0; i < snacks.size() && tf; i++) {
        if (snacks[i].getName() == snackName) {
            snacks[i].setAmount(snacks[i].getAmount() + snackAmount);
            tf = false;
        }
    }
    if (tf) {
        snacks.push_back(Snack(snackName, snackAmount));
    }
    amount += snackAmount;
}

void Storage::eat(std::string snackName, int snackAmount) {
    for (int i = 0; i < snacks.size(); i++) {
        if (snacks[i].getName() == snackName) {
            if (snacks[i].getAmount() < snackAmount)
                throw std::invalid_argument("Not enough snacks");
            snacks[i].setAmount(snacks[i].getAmount() - snackAmount);
            amount -= snackAmount;
            if (snacks[i].getAmount() == 0)
                snacks.erase(snacks.begin() + i);
            return;
        }
    }
    // 沒找到這個 snack
    throw std::invalid_argument("Snack not found");
}

void Storage::eatFirst(int snackAmount) {
    if(snacks[0].getAmount() < snackAmount)
        throw std::invalid_argument("");
    amount -= snackAmount;
    snacks[0].setAmount(snacks[0].getAmount() - snackAmount);
    if (snacks[0].getAmount() == 0) {
        snacks.erase(snacks.begin());
    }
}

void Storage::eatLast(int snackAmount) {
    int index = snacks.size() - 1;
    if(snacks[index].getAmount() < snackAmount)
        throw std::invalid_argument("");
    amount -= snackAmount;
    snacks[index].setAmount(snacks[index].getAmount() - snackAmount);
    if (snacks[index].getAmount() == 0) {
        snacks.erase(snacks.end() - 1);
    }
}

void Storage::sortByAmount() {
    std::sort(snacks.begin(), snacks.end(), [](Snack a, Snack b) {
        return a.getAmount() < b.getAmount();
    });
}

void Storage::sortBySnackName() {
    std::sort(snacks.begin(), snacks.end(), [](Snack a, Snack b) {
        return a.getName() < b.getName();
    });
}

void Storage::clear() {
    snacks.clear();
}

int Storage::getAmount() const{
    return amount;
}

int Storage::getCapacity() const{
    return capacity;

}

StorageType Storage::getType() const{
    return type;
}

const std::vector<Snack>& Storage::getSnacks() const {
    return snacks;
}

void Storage::setCapacity(int storageCapacity) {
    capacity = storageCapacity;
}