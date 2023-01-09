#include <iostream>

int main() {
    const int ARR_SIZE = 100;
    int values[ARR_SIZE] = {};

    std::cout << "Enter first integer term of the array: ";
    std::cin >> values[0];

    for (int i = 1; i < ARR_SIZE; i++) {
        std::cout << "Enter integer: ";
        std::cin >> values[i];

        while (values[i] >= values[i - 1]) {
            std::cout << "The number should be less than " << values[i - 1] << std::endl;
            std::cout << "Enter integer: ";
            std::cin >> values[i];
        }
    }

    for (int i = 0; i < ARR_SIZE; i++) {
        std::cout << values[i] << " ";
    }

    std::cout << std::endl;
 
    return 0;
}