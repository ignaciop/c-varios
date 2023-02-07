#include <iostream>
#include <iomanip>

void printFactors(int n);

int main () {
    for (int i = 1; i <= 100; i++) {
        printFactors(i);
    }

    return 0;
}

void printFactors(int n) {
    std::cout << "Factors of " << std::setw(3) << n << ": {";

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            std::cout << i << ", ";
        }
    }

    std::cout << "\b\b}\n";
}