#include <iostream>
#include <cmath>

double futureValue(double presentValue, double monthly_interest, int months);

int main() {
    double presentValue = 0.0;
    double monthly_interest = 0.0;
    int months = 0;

    std::cout << "Enter present value that you have in your account: ";
    std::cin >> presentValue;
    
    do {
        std::cout << "Enter the monthly interest rate: ";
        std::cin >> monthly_interest;
    } while (monthly_interest < 0.0);
    
    do {
        std::cout << "Enter number of months: ";
        std::cin >> months;
    } while (months < 0);

    monthly_interest /= 100;

    double future = futureValue(presentValue, monthly_interest, months);

    std::cout << "You will have $" << future << " in " << months << " months." << std::endl;
    
    return 0;
}

double futureValue(double presentValue, double monthly_interest, int months) {
    return (presentValue * pow(1 + monthly_interest, months));
}