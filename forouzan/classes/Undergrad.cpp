#include "Undergrad.h"
#include <cassert>
#include <iostream>

Undergrad::Undergrad(std::string sName, double dGpa, int iYear) : Student(sName, dGpa), year(iYear) {
    if (year < 1 || year > 4) {
        std::cout << "Cannot create an undergrad with year under 1 or over 4" << std::endl;
        std::cout << "The program will terminate" << std::endl;

        assert(false);
    }
}

Undergrad::~Undergrad() {}

std::string Undergrad::getName() const {
    return Student::getName();
}

double Undergrad::getGPA() const {
    return Student::getGPA();
}

int Undergrad::getYear() const {
    return year;
}