#include <iostream>

int main() {
    const double PRICE = 199.0F;

    std::cout << "Enter the number of purchased units: ";
    int units = 0;
    std::cin >> units;

    if (units >= 0) {
        double cost = units * PRICE;
        
        if (units < 10) {
            std::cout << "Cost: $" << cost << std::endl;
        } else if (units >= 10 && units <= 19) {
            std::cout << "Cost: $" << cost - cost * 0.2F << std::endl;
        } else if (units >= 20 && units <= 49) {
            std::cout << "Cost: $" << cost - cost * 0.3F << std::endl;
        } else if (units >= 50 && units <= 99) {
            std::cout << "Cost: $" << cost - cost * 0.4F << std::endl;
        } else {
            std::cout << "Cost: $" << cost - cost * 0.5F << std::endl;
        }
    } else {
        std::cout << "The number of units must be greater or equal to 0" << std::endl;
    }

    return 0;
}