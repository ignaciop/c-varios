#include <iostream>

int main () {
    int n = 1;
    int sum = 0;

    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> n;
    } while (n < 1);

    int t = n;

    while (t != 0) {
        sum += t % 10;

        t /= 10;
    }

    std::cout << "Sum of digits of " << n << ": " << sum << std::endl;

    return 0;
}