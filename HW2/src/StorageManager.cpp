#include "StorageManager.hpp"
#include <stdexcept>

StorageManager::StorageManager() {
    storages.push_back(Storage(StorageType::CANDY));
    storages.push_back(Storage(StorageType::COOKIES));
    storages.push_back(Storage(StorageType::CAKE));
    storages.push_back(Storage(StorageType::OTHER));
}

void StorageManager::AddAllStorageCapacity(int capacity) {
    for (int i = 0; i < storages.size(); i++) {
        storages[i].setCapacity(storages[i].getCapacity() + capacity);
    }
}
void StorageManager::moveCapacity(StorageType fromType, StorageType toType, int moveCapacity) {
    if (moveCapacity < 0)
        throw std::invalid_argument("Invalid moveCapacity");

    Storage* fromStorage = nullptr;
    Storage* toStorage = nullptr;

    for (auto &storage : storages) {
        if (storage.getType() == fromType) fromStorage = &storage;
        if (storage.getType() == toType) toStorage = &storage;
    }

    if (!fromStorage || !toStorage)
        throw std::invalid_argument("StorageType not found");

    int available = fromStorage->getCapacity() - fromStorage->getAmount();
    if (available < moveCapacity)
        throw std::invalid_argument("Not enough remaining capacity");

    fromStorage->setCapacity(fromStorage->getCapacity() - moveCapacity);
    toStorage->setCapacity(toStorage->getCapacity() + moveCapacity);
}

std::vector<Storage>& StorageManager::getStorages() {
    return storages;
}
