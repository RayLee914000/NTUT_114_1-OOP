#include "cylinder_engineer.hpp"
#include "staff_no.hpp"

CylinderEngineer::CylinderEngineer(std::string name, std::string phone, int ext, StaffLevel level)
    :Staff(name, Title::CYLINDER_ENGINEER, phone, ext, StaffNo::E, level){

}