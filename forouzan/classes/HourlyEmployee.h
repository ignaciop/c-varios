#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include "Employee2.h"

class HourlyEmployee : public Employee {
    private:
        double hourly_wage;
        double overtime_rate;

    public:
        HourlyEmployee() = delete;
        HourlyEmployee(std::string sName, std::string sEmployeeNumber, std::string sBirthDate, std::string sDateHired, double dHourlyWage, double dOvertimeRate);
        HourlyEmployee(const HourlyEmployee& hourlyEmployeeCopy) = delete;
        ~HourlyEmployee();

        void setHourlyWage(double dHourlyWage);
        void setOvertimeRate(double dOvertimeRate);
        double getHourlyWage() const;
        double getOvertimeRate() const;
};

#endif