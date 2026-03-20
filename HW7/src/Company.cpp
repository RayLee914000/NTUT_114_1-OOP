#include "Company.hpp"
#include <stdexcept>

 Company::Company(std::string name, int floorNumber) {
    this -> name = name;
     this -> floorNumber = floorNumber;
     std::string switchname = "company" + std::to_string(floorNumber) + "_mainPowerSwitch";
     this -> mainSwitch = std::make_shared<MainPowerSwitch>(switchname);
}

std::string Company::getName() {
    return name;
}

int Company::getFloorNumber() {
    return floorNumber;
}
std::shared_ptr<PowerSwitch> Company::getMainSwitch() {
    return mainSwitch;
}
bool Company::isWork() {
    return working;
}
void Company::addPowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch) {
     this->mainSwitch->addPowerSwitch(powerSwitch);
 }

void Company::removePowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch) {
     if (powerSwitch == this->mainSwitch) {
         throw std::invalid_argument("Cannot remove the company main power switch.");
     }
     this->mainSwitch->removePowerSwitch(powerSwitch);
 }

std::vector<std::shared_ptr<PowerSwitch>> Company::findPowerSwitchByName(std::string name) {
     return this->mainSwitch->findPowerSwitchByName(name);
 }

std::vector<std::shared_ptr<Device>> Company::findDeviceByName(std::string name) {
     return this->mainSwitch->findDeviceByName(name);
 }

std::vector<std::shared_ptr<Device>> Company::findDeviceByType(DeviceType type) {
     return this->mainSwitch->findDeviceByDeviceType(type); // 這裡注意你在 MainPowerSwitch 定義的方法名稱
 }

void Company::work() {
     this->working = true;
     this->mainSwitch->turnOn();
 }

void Company::offWork() {
     this->working = false;
     this->mainSwitch->turnOff();
 }

int Company::countPower() {
     return this->mainSwitch->countPower();
 }

