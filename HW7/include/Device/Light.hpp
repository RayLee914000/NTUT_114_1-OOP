#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Device.hpp"

class Light : public Device {
public:
    int intensity;
    Light(std::string name, int power);
    Light(std::string name, int power, int intensity);

    void setIntensity(int intensity);
    int getIntensity();
};

#endif
