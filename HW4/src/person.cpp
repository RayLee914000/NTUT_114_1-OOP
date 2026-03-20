
#include "person.hpp"
#include "title.hpp"
#include <stdexcept>

Person::Person(std::string name, Title title, std::string phone, int ext) {
    this -> name = name;
    this -> title = title;
    this -> phone = phone;
    if (ext < 0) throw std::invalid_argument("");
    this -> ext = ext;
}

std::string Person::GetName(){
    return name;
}

Title Person::GetTitle(){
    // return Title::CYLINDER_ENGINEER;
    return title;
}

std::string Person::GetPhone(){
    return phone;
}

int Person::GetExt(){
    return ext;
}

void Person::SetName(std::string name){
    this->name = name;
}

void Person::SetTitle(Title title){
    this->title = title;
}

void Person::SetPhoneExt(std::string phone, int ext){
    if (ext < 0) throw std::invalid_argument("");
    this -> phone = phone;
    this->ext = ext;
}

bool Person::HaveEMPermission(){
    bool result = false;
    switch (this->title) {
        case Title::PROJECT_MANAGER:
        case Title::CYLINDER_ENGINEER:
        case Title::INFRASTRUCTURE_ENGINEER:
            result = true;
            break;
        default:
            result = false;
    }
    return result;
}