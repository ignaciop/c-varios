#ifndef STUDENT3_H
#define STUDENT3_H

#include <string>
#include "Person2.h"

class Student : public Person {
    private:
        double gpa;

    public:
        Student() = delete;
        Student(std::string sName, double dGpa);
        Student(const Student& studentCopy) = delete;
        ~Student();

        std::string getName() const;
        double getGPA() const; 
};

#endif