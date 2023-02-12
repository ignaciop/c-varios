#include "Course2.h"
#include <iostream>
#include <cassert>

Course::Course() : Course("", 0) {}

Course::Course(std::string sName, int iUnits) : name(sName), units(iUnits) {
    if (units < 0) {
        std::cout << "Cannot create a course with units < 0" << std::endl;
        std::cout << "The program will terminate" << std::endl;

        assert(false);
    }
}

Course::Course(const Course& courseCopy) : Course(courseCopy.name, courseCopy.units) {}

Course::~Course() {}

void Course::print() const {
    std::cout << "Course name: " << name << ", units: " << units << std::endl;
}