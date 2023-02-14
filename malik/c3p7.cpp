#include <iostream>
#include <iomanip>

int main() {
    std::cout << "Enter the net balance: ";
    double net_balance = 0.0;
    std::cin >> net_balance;

    std::cout << "Enter the payment: ";
    double payment = 0.0;
    std::cin >> payment;

    std::cout << "Enter the number of days in the billing cycle: ";
    double d1 = 0.0;
    std::cin >> d1;

    std::cout << "Enter the number of days payment is made before the billing cycle: ";
    double d2 = 0.0;
    std::cin >> d2;

    std::cout << "Enter the interest rate per month: ";
    double interest_rate = 0.0;
    std::cin >> interest_rate;

    double avgDailyBalance = (net_balance * d1 - payment * d2) / d1;
    double interest = avgDailyBalance * interest_rate;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Interest: " << interest << std::endl;

    return 0;
}