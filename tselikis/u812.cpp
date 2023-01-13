#include <iostream>

int main() {
    double arr[] = {1.3, -4.1, -3.8, 9.4, 2.5}, temp, *p1 = arr, *p2 = arr + 4;

    std::cout << "Before: {";

    while (p1 <= p2) {
        std::cout << *p1 << ", ";
        p1++;
    }

    std::cout << "\b\b}\n";

    p1 = arr;

    while (p1 < p2) {
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;

        p1++;
        p2--;
    }

    p1 = arr;
    p2 = arr + 4;

    std::cout << "After: {";
    while (p1 <= p2) {
        std::cout << *p1 << ", ";
        p1++;
    }

    std::cout << "\b\b}\n";

    return 0;
}