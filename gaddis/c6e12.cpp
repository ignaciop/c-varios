#include <iostream>
#include <cmath>

double presentValue(double futureValue, double monthly_interest, int months);

int main() {
    double futureValue = 0.0;
    double annual_interest = 0.0;
    int years = 0;

    std::cout << "Enter future value that you want in your account: ";
    std::cin >> futureValue;
    
    do {
        std::cout << "Enter the annual interest rate: ";
        std::cin >> annual_interest;
    } while (annual_interest < 0.0);
    
    do {
        std::cout << "Enter number of years: ";
        std::cin >> years;
    } while (years < 0);

    double monthly_interest = (annual_interest / 12) / 100;
    int months = years * 12;

    double present = presentValue(futureValue, monthly_interest, months);

    std::cout << "You need to deposit $" << present << " today." << std::endl;
    
    return 0;
}

double presentValue(double futureValue, double monthly_interest, int months) {
    return (futureValue / pow(1 + monthly_interest, months));
}