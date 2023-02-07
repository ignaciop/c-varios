#include "Employee.h"
#include <iostream>
#include <cassert>

Employee::Employee(std::string iName, int iAge, int iServiceYear, int iSalary)
    : name(iName), age(iAge), serviceYear(iServiceYear), salary(iSalary) {

        if (age < 18 || serviceYear < 0) {
            std::cout << "Cannot create employee under 18 years of age or negative service years." << std::endl;
            std::cout << "The program is aborted" << std::endl;

            assert(false);
        }
}

Employee::~Employee() {}

std::string Employee::getName() const {
    return name;
}

int Employee::getAge() const {
    return age;
}

int Employee::getServiceYear() const {
    return serviceYear;
}

int Employee::getSalary() const {
    return salary;
}