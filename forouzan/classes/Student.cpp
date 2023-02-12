#include "Student.h"
#include <cassert>
#include <iostream>
#include <iomanip>

Student::Student() : Student("NONAME", 0.0) {}

Student::Student(std::string sName, double dGpa) : name(sName), gpa(dGpa) {
    if (gpa < 0.0 || gpa > 4.0) {
        std::cout << "Cannot create a student with gpa value under 0.0 or over 4.0" << std::endl;
        std::cout << "The program will terminate" << std::endl;

        assert(false);
    }
}

Student::~Student() {}

void Student::print() const {
    std::cout << "Name: " << name << ", GPA: " << std::fixed 
                << std::setprecision(1) << gpa << std::endl;
}