#include <iostream>
#include <iomanip>
#include <cmath>

int countDigits(int n);
int reverse(int n);
bool isPrime(int n);
bool isEmirp(int n);

int main () {
    int newline = 0;

    for (int i = 1; i < 1000; i++) {
        if (isEmirp(i)) {
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

int countDigits(int n) {
    int count = 0;

    int t = n;

    while (t != 0) {
        count++;

        t /= 10;
    }

    return count;
}

int reverse(int n) {
    int reverse = 0;

    int t = n;

    int digits = countDigits(n);

    while (t != 0) {
        reverse += (t % 10) * pow(10, digits - 1);

        t /= 10;
        digits--;
    }

    return reverse;
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

bool isEmirp(int n) {
    return (isPrime(n) && isPrime(reverse(n)));
}