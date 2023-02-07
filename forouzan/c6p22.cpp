#include <iostream>

int sumDigits(int n);

int main () {
    int n = 1;

    for (int i = 1; i <= 5; i++) {
        std::cout << "\nEnter a positive integer: ";
        std::cin >> n;

        std::cout << "Sum of digits: " << sumDigits(n) << std::endl;
    }
    
    return 0;
}

int sumDigits(int n) {
    int sum = 0;

    int t = n;

    while (t != 0) {
        sum += t % 10;

        t /= 10;
    }

    return sum;
}