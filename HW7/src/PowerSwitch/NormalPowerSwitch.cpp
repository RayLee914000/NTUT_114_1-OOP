#include "PowerSwitch/NormalPowerSwitch.hpp"
#include <stdexcept>

 NormalPowerSwitch::NormalPowerSwitch(std::string name):PowerSwitch(name) {
     device = nullptr;
     state = PowerSwitchState::Off;
}
NormalPowerSwitch::NormalPowerSwitch(std::string name, std::shared_ptr<Device> device):PowerSwitch(name) {
     this -> state = PowerSwitchState::Off;
     this -> device = device;
 }
std::shared_ptr<Device> NormalPowerSwitch::getDevice() {
     return device;
 }

std::string NormalPowerSwitch::getDeviceName() {
     return  device -> getName();
 }
void NormalPowerSwitch::addDevice(std::shared_ptr<Device> device) {
     if (this -> device != nullptr) {
         throw std::invalid_argument("");
     }
     this -> device = device;
 }

std::shared_ptr<Device> NormalPowerSwitch::removeDevice() {
     if (device == nullptr) {
         throw std::invalid_argument("");
     }
     std::shared_ptr<Device> result = device;
     device = nullptr;
     return result;
 }

std::shared_ptr<Device> NormalPowerSwitch::changeDevice(std::shared_ptr<Device> device)
{
     if (this -> device == nullptr) {
         throw std::invalid_argument("");
     }
     std::shared_ptr<Device> result = this -> device;
     this -> device = device;
     return result;
 }

PowerSwitchState NormalPowerSwitch::getState() {
     return state;
 }
void NormalPowerSwitch::turnOn() {
     state = PowerSwitchState::On;
 }
void NormalPowerSwitch::turnOff() {
     state = PowerSwitchState::Off;
 }
void NormalPowerSwitch::flip() {
     if (state == PowerSwitchState::On)
         state = PowerSwitchState::Off;
     else
         state = PowerSwitchState::On;
 }

int NormalPowerSwitch::countPower() {
     if (state == PowerSwitchState::Off)
         return 0;
     return device -> getPower();
 }



