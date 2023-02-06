#include <iostream>

int main () {
    int n = 1;

    do {
        std::cout << "Enter a positive integer between 1 and 100: ";
        std::cin >> n;
    } while (n < 1 || n > 100);

    std::cout << "Factors: {";

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            std::cout << i << ", ";
        }
    }

    std::cout << "\b\b}\n";

    return 0;
}