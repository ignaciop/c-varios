#include <iostream>
#include <cmath>

int main () {
    int m = 1;
    int n = 1;
    int temp = m;

    do {
        std::cout << "Enter a first positive integer: ";
        std::cin >> m;
    } while (m < 1);

    do {
        std::cout << "Enter a second positive integer: ";
        std::cin >> n;
    } while (n < 1);

    while (n != 0) {
        m = abs(m - n);

        if (m < n) {
            temp = m;
            m = n;
            n = temp;
        }
    }

    std::cout << "Greatest common divisor: " << m << std::endl;

    return 0;
}