#include "SalariedEmployee.h"
#include <iostream>
#include <cassert>

SalariedEmployee::SalariedEmployee(std::string sName, std::string sEmployeeNumber, std::string sBirthDate, std::string sDateHired, double dMonthlySalary, double dAnnualBonus)
    : Employee(sName, sEmployeeNumber, sBirthDate, sDateHired), monthly_salary(dMonthlySalary), annual_bonus(dAnnualBonus) {
    if (annual_bonus < 0.0F || annual_bonus > 10.0F) {
        std::cout << "Annual bonus must be between 0 and 10%" << std::endl;
        std::cout << "The program will terminate.";

        assert(false);
    }
}
        
SalariedEmployee::~SalariedEmployee() {}

void SalariedEmployee::setMonthlySalary(double dMonthlySalary) {
    monthly_salary = dMonthlySalary;
}

void SalariedEmployee::setAnnualBonus(double dAnnualBonus) {
    if (annual_bonus < 0.0F || annual_bonus > 10.0F) {
        annual_bonus = 0.0;
    } else {
        annual_bonus = dAnnualBonus;
    }
}

double SalariedEmployee::getMonthlySalary() const {
    return monthly_salary;
}

double SalariedEmployee::getAnnualBonus() const {
    return annual_bonus;
}