#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include "Employee3.h"

class Professor : public Employee {
    private:
        std::string status;

    public:
        Professor() = delete;
        Professor(std::string sName, double dSalary, std::string sStatus);
        Professor(const Professor& professorCopy) = delete;
        ~Professor();

        std::string getName() const;
        double getSalary() const;
        std::string getStatus() const;
};

#endif