#include "vendor.hpp"
#include "service_score.hpp"
#include <stdexcept>
Vendor::Vendor(std::string name, Title title, std::string phone, int ext):Person(name, title, phone, ext){

}

void Vendor::SetServiceScore(ServiceScore score){
    this -> score = score;
}

ServiceScore Vendor::GetServiceScore(){
    return score;
}

int Vendor::GetBonus() {

    switch (score) {
    case ServiceScore::A:
        return 26300;
    case ServiceScore::B:
        return 14900;
    case ServiceScore::C:
        return 7900;
    case ServiceScore::D:
        return 3000;
    default:
        throw std::invalid_argument("");
    }
}
