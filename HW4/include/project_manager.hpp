#ifndef PROJECT_MANAGER_HPP
#define PROJECT_MANAGER_HPP

#include "staff.hpp"
#include <string>
#include "staff_level.hpp"
class ProjectManager : public Staff {
public:
    ProjectManager(std::string name, std::string phone, int ext, StaffLevel level);
};

#endif