#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include "title.hpp"

class Person {
private:
    std::string name;
    Title title;
    std::string phone;
    int ext;
public:
    Person(std::string name, Title title, std::string phone, int ext);

    std::string GetName();
    Title GetTitle();
    std::string GetPhone();
    int GetExt();
    void SetName(std::string name);
    void SetTitle(Title title);
    void SetPhoneExt(std::string phone, int ext);
    bool HaveEMPermission();
};

#endif