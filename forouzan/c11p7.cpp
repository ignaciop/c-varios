#include <iostream>
#include "classes/Student2.h"
#include "classes/Course2.h"

int main() {
    Student student("John Doe", 3.5, 3);

    student.addCourse(0, Course("Math 101", 4));
    student.addCourse(1, Course("English 101", 3));
    student.addCourse(2, Course("Computer Science 101", 5));

    student.print();

    return 0;
}