#include "Device/Device.hpp"

 Device::Device(DeviceType deviceType, std::string name, int power) {
    this -> devicetype = deviceType;
     this -> name = name;
     this -> power = power;
}

DeviceType Device::getDeviceType() {
    return devicetype;
}
std::string Device::getName() {
    return name;
}
int Device::getPower() {
    return power;
}



