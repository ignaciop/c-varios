#include <iostream>

int main() {
    std::cout << "Enter a value: ";
    float x;
    std::cin >> x;

    if (x < -5) {
        std::cout << "8" << std::endl;
    } else if (x >= -5 && x < 3) {
        std::cout << 1 / x << std::endl;
    } else if (x >= 3 && x < 12) {
        std::cout << x * x - 4 << std::endl;
    } else {
        std::cout << 6 / ((x - 14) * (x - 14)) << std::endl;
    }

    return 0;
}