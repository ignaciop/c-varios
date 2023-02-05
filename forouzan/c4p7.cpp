#include <iostream>

int main() {
    std::cout << "Number of units: ";
    int units = 0;
    std::cin >> units;

    std::cout << "Price per unit: ";
    double price_per_unit = 0.0;
    std::cin >> price_per_unit;

    double price_after = units * price_per_unit;

    if (units >= 10 && units <= 49) {
        price_after -= price_after * 0.03F;
    } else if (units >= 50 && units <= 99) {
        price_after -= price_after * 0.05F;
    } else if (units >= 100) {
        price_after -= price_after * 0.1F;
    }

    std::cout << "Total price after discount: $" << price_after << std::endl;
    
    return 0;
}