#include <iostream>

int main() {
    std::cout << "Enter annual income: ";
    float income = 0.0;
    std::cin >> income;

    float tax = 0.0;

    if (income >= 12001 && income <= 14000) {
        tax = (income - 12000) * 0.15;
    } else if (income >= 14001 && income <= 30000) {
        tax = (14000 - 12000) * 0.15 + (income - 14000) * 0.3;
    } else if (income > 30000) {
        tax = (14000 - 12000) * 0.15 + (30000 - 14000) * 0.3 + (income - 30000) * 0.4;
    }

    std::cout << "Tax: " << tax << std::endl;

    return 0;
}