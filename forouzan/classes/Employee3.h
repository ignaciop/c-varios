#ifndef EMPLOYEE3_H
#define EMPLOYEE3_H

#include <string>
#include "Person2.h"

class Employee : public Person {
    private:
        double salary;

    public:
        Employee() = delete;
        Employee(std::string sName, double dSalary);
        Employee(const Employee& employeeCopy) = delete;
        ~Employee();

        std::string getName() const;
        double getSalary() const; 
};

#endif