#include "Student3.h"
#include <cassert>
#include <iostream>

Student::Student(std::string sName, double dGpa) : Person(sName), gpa(dGpa) {
    if (gpa < 0.0 || gpa > 4.0) {
        std::cout << "Cannot create a student with gpa value under 0.0 or over 4.0" << std::endl;
        std::cout << "The program will terminate" << std::endl;

        assert(false);
    }
}

Student::~Student() {}

std::string Student::getName() const {
    return Person::getName();
}

double Student::getGPA() const {
    return gpa;
}