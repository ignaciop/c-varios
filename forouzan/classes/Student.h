#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
    private:
        std::string name;
        double gpa;
        
    public:
        Student();
        Student(std::string sName, double dGpa);
        Student(const Student& studentCopy) = delete;
        ~Student();

        void print() const;
};

#endif