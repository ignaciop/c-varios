#include "Employee2.h"
#include <iostream>

Employee::Employee(std::string sName, std::string sEmployeeNumber, std::string sBirthDate, std::string sDateHired)
 : name(sName), employee_number(sEmployeeNumber), birth_date(sBirthDate), date_hired(sDateHired) {}
        
Employee::~Employee() {}

std::string Employee::getName() const {
    return name;
}

std::string Employee::getEmployeeNumber() const {
    return employee_number;
}

std::string Employee::getBirthDate() const {
    return birth_date;
}

std::string Employee::getDateHired() const {
    return date_hired;
}