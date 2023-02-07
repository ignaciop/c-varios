#include <iostream>

int countDigits(int n);

int main () {
    int n = 1;

    for (int i = 1; i <= 10; i++) {
        do {
            std::cout << "\nEnter a positive integer: ";
            std::cin >> n;
        } while (n < 1);

        std::cout << "Digits: " << countDigits(n) << std::endl;
    }
    
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