#include "Professor.h"
#include <cassert>
#include <iostream>

Professor::Professor(std::string sName, double dSalary, std::string sStatus) : Employee(sName, dSalary), status(sStatus) {
    if (status != "part-time" && status != "full-time") {
        std::cout << "Cannot create a professor with status not equal to part-time or full-time" << std::endl;
        std::cout << "The program will terminate" << std::endl;

        assert(false);
    }
}

Professor::~Professor() {}

std::string Professor::getName() const {
    return Employee::getName();
}

double Professor::getSalary() const {
    return Employee::getSalary();
}

std::string Professor::getStatus() const {
    return status;
}