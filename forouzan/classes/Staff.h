#ifndef STAFF_H
#define STAFF_H

#include <string>
#include "Employee3.h"

class Staff : public Employee {
    private:
        std::string status;

    public:
        Staff() = delete;
        Staff(std::string sName, double dSalary, std::string sStatus);
        Staff(const Staff& staffCopy) = delete;
        ~Staff();

        std::string getName() const;
        double getSalary() const;
        std::string getStatus() const;
};

#endif