#include <iostream>

int main() {
    const double PERCENTAGE = 0.8;

    std::cout << "Enter the replacement cost of your building: ";
    double replacement_cost = 0.0;
    std::cin >> replacement_cost;

    double insurance = replacement_cost * PERCENTAGE;

    std::cout << "Minimum insurance: $" << insurance << std::endl;

    return 0;
}