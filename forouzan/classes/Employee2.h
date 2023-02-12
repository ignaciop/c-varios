#ifndef EMPLOYEE2_H
#define EMPLOYEE2_H

#include <string>

class Employee {
    private:
        std::string name;
        std::string employee_number;
        std::string birth_date;
        std::string date_hired;

    public:
        Employee() = delete;
        Employee(std::string sName, std::string sEmployeeNumber, std::string sBirthDate, std::string sDateHired);
        Employee(const Employee& employeeCopy) = delete;
        ~Employee();

        std::string getName() const;
        std::string getEmployeeNumber() const;
        std::string getBirthDate() const;
        std::string getDateHired() const;
};

#endif