#ifndef VENDOR_HPP
#define VENDOR_HPP

#include <string>
#include "service_score.hpp"
#include "title.hpp"
#include "person.hpp"

class Vendor:public Person{
private:
    ServiceScore score;
public:
    Vendor(std::string name, Title title, std::string phone, int ext);
    void SetServiceScore(ServiceScore score);
    ServiceScore GetServiceScore();
    virtual int GetBonus();
};

#endif