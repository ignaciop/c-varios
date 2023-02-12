#include "Employee3.h"

Employee::Employee(std::string sName, double dSalary) : Person(sName), salary(dSalary) {}

Employee::~Employee() {}

std::string Employee::getName() const {
    return Person::getName();
}

double Employee::getSalary() const {
    return salary;
}