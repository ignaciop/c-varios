#include <iostream>

int main() {
    const double TAX = 9.0F;

    std::cout << "Enter the sale amount: " << std::endl;
    double sale = 0.0;
    std::cin >> sale;

    double tax = sale * TAX / 100;
    double total = sale + tax;

    std::cout << "Sale amount:      $ " << sale << std::endl;
    std::cout << "Tax amount:       $ " << tax << std::endl;
    std::cout << "Total amount due: $ " << total << std::endl;

    return 0;
}