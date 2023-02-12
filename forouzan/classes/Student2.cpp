#include "Student2.h"
#include <cassert>
#include <iostream>

Student::Student(std::string sName, double dGpa, int iNumCourses) : name(sName), gpa(dGpa), numCourses(iNumCourses) {
    if (gpa < 0.0 || gpa > 4.0 || numCourses < 0) {
        std::cout << "Cannot create a student with gpa value under 0.0 or over 4.0" << std::endl;
        std::cout << "The program will terminate" << std::endl;

        assert(false);
    }

    courses = new Course[numCourses];
}

Student::~Student() {
    delete[] courses;
}

void Student::addCourse(int index, const Course& c) {
    if (index >= 0 && index < numCourses) {
        courses[index] = c;
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}

void Student::print() const {
    std::cout << "List of courses for " << name << ": " << std::endl;

    for (int i = 0; i < numCourses; i++) {
        courses[i].print();
    }

    std::cout << std::endl;
}