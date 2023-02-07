#include <iostream>

unsigned int factorial(int n);

int main () {
    int n = 1;

    do {
        std::cout << "Enter a number between 1 and 20: ";
        std::cin >> n;
    } while (n < 1 || n > 20);

    std::cout << n << "! = " << factorial(n) << std::endl;
    
    return 0;
}

unsigned int factorial(int n) {
    if (n == 1 || n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
    