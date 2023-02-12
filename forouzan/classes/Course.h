#ifndef COURSE_H
#define COURSE_H

#include "Student.h"

class Course {
    private:
        int capacity;
        Student* students;

    public:
        Course();
        Course(int iStudentsNumber);
        Course(const Course& courseCopy);
        ~Course();

        void addStudent(int index, const Student& s);
        void print() const;
};

#endif