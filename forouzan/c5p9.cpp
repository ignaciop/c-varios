#include <iostream>

int main () {
    int n1 = 1;
    int n2 = 1;

    do {
        std::cout << "Enter a first positive integer between 1 and 100: ";
        std::cin >> n1;
    } while (n1 < 1 || n1 > 100);

    do {
        std::cout << "Enter a second positive integer between 1 and 100: ";
        std::cin >> n2;
    } while (n2 < 1 || n2 > 100);

    int min = ((n1 < n2) ? n1 : n2);

    std::cout << "Common factors: {";

    for (int i = 1; i <= min; i++) {
        if (n1 % i == 0 && n2 % i == 0) {
            std::cout << i << ", ";
        }
    }

    std::cout << "\b\b}\n";

    return 0;
}