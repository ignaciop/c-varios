#include <iostream>

int main() {
    std::cout << "Enter an integer value: ";
    int value {};
    std::cin >> value;

    if (value >= 1 && value <= 100) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "Out of range." << std::endl;
    }

    return 0;
}