#include <iostream>

int pot(int base, int exp);

int main() {
    long n = pot(6, 5);

    std::cout << "6^5 = " << n << std::endl;

    return 0;
}

int pot(int base, int exp) {
    long res {1};

    for (int i = 1; i <= exp; i++) {
        res *= base;
    }

    return res;
}