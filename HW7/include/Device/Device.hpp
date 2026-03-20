#ifndef DEVICE_HPP
#define DEVICE_HPP

#include "DeviceType.hpp"
#include <string>

class Device{
private:
    DeviceType devicetype;
    std::string name;
    int power;
public:
    Device(DeviceType deviceType, std::string name, int power);

    DeviceType getDeviceType();
    std::string getName();
    int getPower();
};

#endif
