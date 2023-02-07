#include <iostream>
#include <iomanip>
#include <cmath>

bool isPrime(int n);
void printPrimeFactors(int n);

int main () {
    for (int i = 1; i <= 100; i++) {
        printPrimeFactors(i);
    }

    return 0;
}

bool isPrime(int n) {
    bool prime = true;

    double sq_root = sqrt(n);

    for (int i = 2; i <= sq_root; i++) {
        if (n % i == 0) {
            prime = !prime;
            break;
        }
    }

    return prime;
}

void printPrimeFactors(int n) {
    std::cout << "Prime factors of " << std::setw(3) << n << ": {";

    for (int i = 1; i <= n; i++) {
        if (n % i == 0 && isPrime(i)) {
            std::cout << i << ", ";
        }
    }

    std::cout << "\b\b}\n";
}