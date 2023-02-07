#include <iostream>

unsigned int factorial(int n);
unsigned int permutations(int n, int k);

int main () {
    int n = 1;
    int k = 0;

    do {
        std::cout << "Enter a number of objects between 1 and 20: ";
        std::cin >> n;
    } while (n < 1 || n > 20);

    do {
        std::cout << "Enter a number of elements : ";
        std::cin >> k;
    } while (k > n || k < 0);

    std::cout << "P(" << n << ", " << k << ") = " << permutations(n, k) << std::endl;
    
    return 0;
}

unsigned int factorial(int n) {
    if (n == 1 || n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

unsigned int permutations(int n, int k) {
    return (factorial(n) / factorial(n - k));
}