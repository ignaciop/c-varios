#include <iostream>

int main() {
    int a = 0;
    int b = 0;
    int c = 0;

    while (true) {
        NUMBER_INSERTION:
        std::cout << "Enter first integer: ";
        std::cin >> a;

        std::cout << "Enter second integer: ";
        std::cin >> b;

        std::cout << "Enter third integer: ";
        std::cin >> c;

        if (a <= b || b <= c) {
            std::cout << "\nPlease enter the numbers in descending order!\n" << std::endl;

            goto NUMBER_INSERTION;
        }

        if (a > b && b > c) {
            break;
        }
    }

    std::cout << a << " > " << b << " > " << c << std::endl;

    return 0;
}