#include "HourlyEmployee.h"
#include <iostream>
#include <cassert>

HourlyEmployee::HourlyEmployee(std::string sName, std::string sEmployeeNumber, std::string sBirthDate, std::string sDateHired, double dHourlyWage, double dOvertimeRate)
    : Employee(sName, sEmployeeNumber, sBirthDate, sDateHired), hourly_wage(dHourlyWage), overtime_rate(dOvertimeRate) {
    if (overtime_rate < 50.0F || overtime_rate > 100.0F) {
        std::cout << "Overtime rate must be between 50 and 100%" << std::endl;
        std::cout << "The program will terminate.";

        assert(false);
    }
}
        
HourlyEmployee::~HourlyEmployee() {}

void HourlyEmployee::setHourlyWage(double dHourlyWage) {
    hourly_wage = dHourlyWage;
}

void HourlyEmployee::setOvertimeRate(double dOvertimeRate) {
    if (dOvertimeRate < 50.0F || dOvertimeRate > 100.0F) {
        overtime_rate = 0.0;
    } else {
        overtime_rate = dOvertimeRate;
    }
}

double HourlyEmployee::getHourlyWage() const {
    return hourly_wage;
}

double HourlyEmployee::getOvertimeRate() const {
    return overtime_rate;
}