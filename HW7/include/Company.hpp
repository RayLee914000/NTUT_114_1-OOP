#ifndef COMPANY_HPP
#define COMPANY_HPP

#include "Device/Device.hpp"
#include "PowerSwitch/MainPowerSwitch.hpp"
#include <string>
#include <vector>
#include <memory>

class Company {
private:
    std::string name;
    int floorNumber;
    std::shared_ptr<MainPowerSwitch> mainSwitch;
    bool working;
public:
    Company(std::string name, int floorNumber);

    std::string getName();
    int getFloorNumber();
    std::shared_ptr<PowerSwitch> getMainSwitch();
    bool isWork();

    void addPowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch);
    void removePowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch);

    std::vector<std::shared_ptr<PowerSwitch>> findPowerSwitchByName(std::string name);
    std::vector<std::shared_ptr<Device>> findDeviceByName(std::string name);
    std::vector<std::shared_ptr<Device>> findDeviceByType(DeviceType type);

    void work();
    void offWork();

    int countPower();
};

#endif
