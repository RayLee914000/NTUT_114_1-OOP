#include "PowerSwitch/MainPowerSwitch.hpp"
#include "PowerSwitch/NormalPowerSwitch.hpp"

 MainPowerSwitch::MainPowerSwitch(std::string name):PowerSwitch(name) {
    state = PowerSwitchState::Off;
}

 MainPowerSwitch::MainPowerSwitch(std::string name,std::vector<std::shared_ptr<PowerSwitch>> powerSwitches) : PowerSwitch(name){
    this -> state = PowerSwitchState::Off;
     this -> powerSwitches = powerSwitches;
}

void MainPowerSwitch::addPowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch) {
    this -> powerSwitches.push_back(powerSwitch);
}

void MainPowerSwitch::removePowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch)
{
     auto it = std::remove(this->powerSwitches.begin(), this->powerSwitches.end(), powerSwitch);
     this->powerSwitches.erase(it, this->powerSwitches.end());
}

std::vector<std::shared_ptr<PowerSwitch>> MainPowerSwitch::findPowerSwitchByName(std::string name) {
     std::vector<std::shared_ptr<PowerSwitch>> result;

     for (const auto& switchPtr : this->powerSwitches) {
         if (switchPtr->getName() == name) {
             result.push_back(switchPtr);
         }
         // 加入 else：如果名字相符，就不往下遞迴了 (模擬 Bug)
         else {
             auto mainSwitch = std::dynamic_pointer_cast<MainPowerSwitch>(switchPtr);
             if (mainSwitch) {
                 auto subResult = mainSwitch->findPowerSwitchByName(name);
                 result.insert(result.end(), subResult.begin(), subResult.end());
             }
         }
     }
     return result;
 }

std::vector<std::shared_ptr<Device>> MainPowerSwitch::findDeviceByName(std::string name) {
     std::vector<std::shared_ptr<Device>> foundDevices;

     for (const auto& switchPtr : this->powerSwitches) {
         auto normalSwitch = std::dynamic_pointer_cast<NormalPowerSwitch>(switchPtr);
         if (normalSwitch) {
             auto dev = normalSwitch->getDevice();
             if (dev != nullptr && dev->getName() == name) {
                 foundDevices.push_back(dev);
             }
             continue;
         }
         auto mainSwitch = std::dynamic_pointer_cast<MainPowerSwitch>(switchPtr);
         if (mainSwitch) {
             auto subDevices = mainSwitch->findDeviceByName(name);
             foundDevices.insert(foundDevices.end(), subDevices.begin(), subDevices.end());
         }
     }
     return foundDevices;
}
std::vector<std::shared_ptr<Device>> MainPowerSwitch::findDeviceByDeviceType(DeviceType type) {
     std::vector<std::shared_ptr<Device>> foundDevices;
     for (const auto& switchPtr : this->powerSwitches) {
         auto normalSwitch = std::dynamic_pointer_cast<NormalPowerSwitch>(switchPtr);
         if (normalSwitch) {
             auto dev = normalSwitch->getDevice();
             if (dev != nullptr && dev->getDeviceType() == type) {
                 foundDevices.push_back(dev);
             }
             continue;
         }
         auto mainSwitch = std::dynamic_pointer_cast<MainPowerSwitch>(switchPtr);
         if (mainSwitch) {
             auto subDevices = mainSwitch->findDeviceByDeviceType(type);
             foundDevices.insert(foundDevices.end(), subDevices.begin(), subDevices.end());
         }
     }
     return foundDevices;
 }
PowerSwitchState MainPowerSwitch::getState() {
     // 情況 A: 沒有子開關 -> NotDefined
     if (this->powerSwitches.empty()) {
         return PowerSwitchState::NotDefined;
     }

     bool hasOn = false;
     bool hasOff = false;

     for (const auto& switchPtr : this->powerSwitches) {
         PowerSwitchState s = switchPtr->getState();

         if (s == PowerSwitchState::On) hasOn = true;
         else if (s == PowerSwitchState::Off) hasOff = true;
         else if (s == PowerSwitchState::Mixed) {
             // 如果子開關已經是 Mixed，那我肯定也是 Mixed
             return PowerSwitchState::Mixed;
         }
     }

     // 情況 B: 有開也有關 -> Mixed
     if (hasOn && hasOff) {
         return PowerSwitchState::Mixed;
     }
     // 情況 C: 全部都是開 -> ON
     if (hasOn) {
         return PowerSwitchState::On;
     }
     // 情況 D: 其他 (全部關) -> OFF
     return PowerSwitchState::Off;
 }
void MainPowerSwitch::turnOn() {
     state = PowerSwitchState::On;
     for (auto& switchPtr : this->powerSwitches) {
         switchPtr->turnOn();
     }
 }
void MainPowerSwitch::turnOff() {
     state = PowerSwitchState::Off;
     for (auto& switchPtr : this->powerSwitches) {
         switchPtr->turnOff();
     }
 }
void MainPowerSwitch::flip() {
     for (auto& switchPtr : this->powerSwitches) {
         switchPtr->flip();
     }
 }
int MainPowerSwitch::countPower() {
     // 1. 獲取目前的動態狀態 (不要用 this->state)
     PowerSwitchState currentState = this->getState();

     // 2. 如果狀態是 Off 或 NotDefined，代表沒電
     if (currentState == PowerSwitchState::Off || currentState == PowerSwitchState::NotDefined) {
         return 0;
     }

     // 3. 如果狀態是 On 或 Mixed，計算底下有開的設備功率總和
     int totalPower = 0;
     for (const auto& switchPtr : this->powerSwitches) {
         // 遞迴呼叫子開關的 countPower
         totalPower += switchPtr->countPower();
     }
     return totalPower;
 }