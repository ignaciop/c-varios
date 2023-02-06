#include <iostream>
#include <cmath>

int main () {
    int n = 1;
    int countDigits = 0;
    int reverse = 0;

    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> n;
    } while (n < 1);

    int t = n;

    while (t != 0) {
        countDigits++;

        t /= 10;
    }

    t = n;

    while (t != 0) {
        reverse += (t % 10) * pow(10, countDigits - 1);

        t /= 10;
        countDigits--;
    }

    if (n == reverse) {
        std::cout << n << " is a palindrome" << std::endl;
    } else {
        std::cout << n << " is not a palindrome" << std::endl;
    }

    return 0;
}