#include "Graduate.h"
#include <cassert>
#include <iostream>

Graduate::Graduate(std::string sName, double dGpa, std::string sGoal) : Student(sName, dGpa), goal(sGoal) {
    if (goal != "master" && goal != "phd") {
        std::cout << "Cannot create a graduate with goals not equal to master or phd" << std::endl;
        std::cout << "The program will terminate" << std::endl;

        assert(false);
    }
}

Graduate::~Graduate() {}

std::string Graduate::getName() const {
    return Student::getName();
}

double Graduate::getGPA() const {
    return Student::getGPA();
}

std::string Graduate::getGoal() const {
    return goal;
}