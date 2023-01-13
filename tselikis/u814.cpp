#include <iostream>

int main() {
    const int ARRAY_SIZE = 100;
    int numbers[ARRAY_SIZE] = {};

    int *p = nullptr;

    for (p = numbers; p <= numbers + (ARRAY_SIZE - 1); p++) {
        std::cout << "Enter integer number: ";
        std::cin >> *p;
    }

    for (p = numbers; p <= numbers + (ARRAY_SIZE - 1); p++) {
        int *temp = nullptr;

        for (temp = numbers; temp <= numbers + (ARRAY_SIZE - 1); temp++) {
            if (*temp == *p && p != temp) {
                *temp = -99;
            }
        }
    }

    std::cout << "{";

    for (p = numbers; p <= numbers + (ARRAY_SIZE - 1); p++) {
        std::cout << *p << ", ";
    }

    std::cout << "\b\b}\n";

    return 0;
}