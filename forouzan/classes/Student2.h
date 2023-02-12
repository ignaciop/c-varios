#ifndef STUDENT2_H
#define STUDENT2_H

#include <string>
#include "Course2.h"

class Student {
    private:
        std::string name;
        double gpa;
        int numCourses;
        Course *courses;

    public:
        Student() = delete;
        Student(std::string sName, double dGpa, int iNumCourses);
        Student(const Student& studentCopy) = delete;
        ~Student();

        void addCourse(int index, const Course& c);
        void print() const;
};

#endif