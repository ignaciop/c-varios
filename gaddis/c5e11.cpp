#include <iostream>

int main() {
    const double PERCENTAGE = 0.03F;

    double membership = 3000.0;

    std::cout << "Current membership fee: $" << membership << std::endl;

    for (int i = 1; i <= 5; i++) {
        membership += membership * PERCENTAGE;

        std::cout << "Year " << i << ": $" << membership << std::endl;
    }

    return 0;
}