#include <iostream>
#include <iomanip>
#include <cmath>

bool isPrime(int n);

int main () {
    int newline = 0;

    for (int i = 2; i < 500; i++) {
        if (isPrime(i)) {
            std::cout << std::setw(4) << i << " ";

            newline++;
        }

        if (newline % 10 == 0) {
            std::cout << "\n";
        }
    }

    std::cout << "\n";
    
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