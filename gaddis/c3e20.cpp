#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::cout << "Enter the principal: ";
    double principal = 0.0;
    std::cin >> principal;

    std::cout << "Enter the annual interest rate: ";
    double rate = 0.0;
    std::cin >> rate;

    std::cout << "Enter the number of times the interest is compounded: ";
    int t = 0;
    std::cin >> t;

    double balance = principal * pow(1 + (rate / 100) / t, t);
    double interest = balance - principal;

    std::cout << "Interest rate: " << std::setw(7) << std::setw(13) << std::fixed << std::setprecision(2) << std::right << rate << "%" << std::endl;
    std::cout << "Times Compounded: " << std::setw(4) << std::setw(11) << std::right << t << std::endl;
    std::cout << "Principal: " << std::setw(11) << "$ " << std::setw(7) << std::fixed << std::setprecision(2) << std::right << principal << std::endl;
    std::cout << "Interest: " << std::setw(12) << "$ " << std::setw(7) << std::fixed << std::setprecision(2) << std::right << interest << std::endl;
    std::cout << "Final balance: " << std::setw(7) << "$ " << std::setw(7) << std::fixed << std::setprecision(2) << std::right << balance << std::endl; 
    
    return 0;
}