#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::cout << "Enter the monthly interest rate: ";
    double rate = 0.0;
    std::cin >> rate;

    std::cout << "Enter the number of payments: ";
    int n = 0;
    std::cin >> n;

    std::cout << "Enter the loan amount: ";
    double l = 0.0;
    std::cin >> l;

    double payment = l * ((rate / 100) * pow(1 + (rate / 100), n)) / ((pow(1 + (rate / 100), n)) - 1);

    std::cout << "\nLoan amount: " << std::setw(14) << "$ " << std::setw(7) << std::fixed << std::setprecision(2) << std::right << l << std::endl; 
    std::cout << "Monthly Interest Rate: " << std::setw(11) << std::fixed << std::setprecision(2) << std::right << rate << "%" << std::endl;
    std::cout << "Number of Payments: " << std::setw(15) << std::right << n << std::endl;
    std::cout << "Monthly Payment: " << std::setw(11) << "$ " << std::setw(7) << std::fixed << std::setprecision(2) << std::right << payment << std::endl;
    std::cout << "Amount Paid Back: " << std::setw(9) << "$ " << std::setw(7) << std::fixed << std::setprecision(2) << std::right << n * payment << std::endl;
    std::cout << "Interest Paid: " << std::setw(13) << "$ " << std::setw(7) << std::fixed << std::setprecision(2) << std::right << n * payment - l << std::endl; 
    
    return 0;
}