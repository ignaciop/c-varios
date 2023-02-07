#include <iostream>
#include <iomanip>

bool isPrime(int n);

int main () {
    int newline = 0;

    for (int i = 2; i < 100; i++) {
        if (isPrime(i)) {
            std::cout << std::setw(2) << i << " ";

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

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            prime = !prime;
            break;
        }
    }

    return prime;
}