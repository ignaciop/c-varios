#include <iostream>

int main() {
    const double YEN_PER_DOLLAR = 129.56F;
    const double EUROS_PER_DOLLAR = 0.92F;

    std::cout << "Enter amount in U.S. dollars: ";
    double dollars = 0.0;
    std::cin >> dollars;

    double y2d = dollars * YEN_PER_DOLLAR;
    double e2d = dollars * EUROS_PER_DOLLAR;

    std::cout << dollars << " U.S. dollars are " << y2d << " Yen and "
               << e2d << " Euros." << std::endl;

    return 0;
}