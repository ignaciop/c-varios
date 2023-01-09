#include <iostream>

int main() {
    const int ARR_SIZE = 10;
    int numbers[ARR_SIZE] = {};
    int number = 1;

    for (int i = 0; i < ARR_SIZE; i++) {
        do {
            std::cout << "Enter numbers[" << i << "]: ";
            std::cin >> number;

        } while (number == 0 || number == -1);

        if (((i % 2 == 0) && (number % 2 == 0)) || ((i % 2 != 0) && (number % 2 != 0))) {
            numbers[i] = number;
        } else {
            numbers[i] = -1;
        }
    }
    
    std::cout << std::endl;

    for (int i = 0; i < ARR_SIZE; i++) {
        std::cout << "numbers[" << i << "]: " << numbers[i] << std::endl;
    }

    std::cout << std::endl;

    return 0;
}