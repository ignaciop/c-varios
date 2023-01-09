#include <iostream>

int main() {
    const int ARR_SIZE = 100;
    int values[ARR_SIZE] = {};


    for (int i = 0; i < ARR_SIZE; i++) {
        std::cout << "Enter integer value: ";
        std::cin >> values[i];
    }
 
    int x = values[ARR_SIZE - 1];

    for (int i = ARR_SIZE - 1; i > 0; i--) {
        values[i] = values[i - 1];
    }

    values[0] = x;

    for (int i = 0; i < ARR_SIZE; i++) {
        std::cout << values[i] << " ";
    }

    std::cout << std::endl;
 
    return 0;
}