#include "Course.h"
#include <iostream>
#include <cassert>

Course::Course() : Course(5) {}

Course::Course(int iStudentsNumber) : capacity(iStudentsNumber) {
    students = new Student[capacity];
}

Course::Course(const Course& courseCopy) {
    capacity = courseCopy.capacity;
    students = new Student[capacity];

    for (int i = 0; i < capacity; i++) {
        students[i] = courseCopy.students[i];
    }
}
    
Course::~Course() {
    delete[] students;
}

void Course::addStudent(int index, const Student& s) {
    if (index >= 0 && index < capacity) {
        students[index] = s;
    } else {
        std::cout << "Invalid index" << std::endl;
    }
}

void Course::print() const {
    std::cout << "List of Students" << std::endl;

    for (int i = 0; i < capacity; i++) {
        students[i].print();
    }

    std::cout << std::endl;
}