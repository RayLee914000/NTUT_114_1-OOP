#ifndef NORMALPOWERSWITCH_HPP
#define NORMALPOWERSWITCH_HPP

#include "PowerSwitch.hpp"
#include "Device/Device.hpp"
#include <memory>

class NormalPowerSwitch : public PowerSwitch{
private:
    PowerSwitchState state;
    std::shared_ptr<Device> device;
public:
    NormalPowerSwitch(std::string name);
    NormalPowerSwitch(std::string name, std::shared_ptr<Device> device);

    std::shared_ptr<Device> getDevice();
    std::string getDeviceName();
    void addDevice(std::shared_ptr<Device> device);
    std::shared_ptr<Device> removeDevice();
    std::shared_ptr<Device> changeDevice(std::shared_ptr<Device> device);

    PowerSwitchState getState() override;
    void turnOn() override;
    void turnOff() override;
    void flip() override;
    int countPower() override;
};

#endif
