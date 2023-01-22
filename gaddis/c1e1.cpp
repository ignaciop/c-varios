#include <iostream>

int main() {
    double candy, rate, pay;

    std::cout << "How many candy bars you sold? ";
    std::cin >> candy;

    std::cout << "How much do you get paid per candy bar? ";
    std::cin >> rate;

    pay = candy * rate;

    std::cout << "You have earned $" << pay << std::endl;

    return 0;
}