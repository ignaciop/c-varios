#include "Staff.h"
#include <cassert>
#include <iostream>

Staff::Staff(std::string sName, double dSalary, std::string sStatus) : Employee(sName, dSalary), status(sStatus) {
    if (status != "manager" && status != "nonmanager") {
        std::cout << "Cannot create a staff with status not equal to manager or nonmanager" << std::endl;
        std::cout << "The program will terminate" << std::endl;

        assert(false);
    }
}

Staff::~Staff() {}

std::string Staff::getName() const {
    return Employee::getName();
}

double Staff::getSalary() const {
    return Employee::getSalary();
}

std::string Staff::getStatus() const {
    return status;
}