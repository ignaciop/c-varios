#include <iostream>
#include "classes/Student.h"
#include "classes/Course.h"

int main() {
    Student s1("John Doe", 2.5);
    Student s2("Mary Jane", 3.2);
    Student s3("Dave Matthews", 1.4);
    Student s4("Gregory House", 3.8);
    Student s5("Leo Messi", 4.0);

    Course c1;
    c1.addStudent(0, s1);
    c1.addStudent(1, s2);
    c1.addStudent(2, s3);
    c1.addStudent(3, s4);
    c1.addStudent(4, s5);
    c1.print();

    Course c2(c1);
    c2.print();

    Course c3(2);
    c3.addStudent(0, s2);
    c3.addStudent(1, s5);
    c3.print();

    return 0;
}