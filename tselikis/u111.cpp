#include <iostream>

int check_numbers(int a, int b, int c);

int main() {
    std::cout << "Enter first integer: ";
    int a;
    std::cin >> a;

    std::cout << "Enter second integer: ";
    int b;
    std::cin >> b;

    std::cout << "Enter third integer: ";
    int c;
    std::cin >> c;

    int res = check_numbers(a, b, c);

    std::cout << res << std::endl;

    return 0;
}

int check_numbers(int a, int b, int c) {
    if (a + b == c) {
        return ((a > b) ? a : b);
    } else {
        return ((b > c) ? c : b);
    }
}