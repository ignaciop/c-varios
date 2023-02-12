#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include "Employee2.h"

class SalariedEmployee : public Employee {
    private:
        double monthly_salary;
        double annual_bonus;

    public:
        SalariedEmployee() = delete;
        SalariedEmployee(std::string sName, std::string sEmployeeNumber, std::string sBirthDate, std::string sDateHired, double dMonthlySalary, double dAnnualBonus);
        SalariedEmployee(const SalariedEmployee& salariedEmployeeCopy) = delete;
        ~SalariedEmployee();

        void setMonthlySalary(double dMonthlySalary);
        void setAnnualBonus(double dAnnualBonus);
        double getMonthlySalary() const;
        double getAnnualBonus() const;
};

#endif