#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
    private:
        std::string name;
        int age;
        int serviceYear;
        double salary;

    public:
        Employee() = delete;
        Employee(std::string iName, int iAge, int iServiceYear, int iSalary);
        Employee(const Employee& employeeCopy) = delete;
        ~Employee();

        std::string getName() const;
        int getAge() const;
        int getServiceYear() const;
        int getSalary() const;
};

#endif