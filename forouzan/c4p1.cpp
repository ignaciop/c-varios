#include <iostream>

int main() {
    std::cout << "Please enter a two-digit integer: ";
    unsigned int number = 0;
    std::cin >> number;

    if (number < 10 || number > 99) {
        return 0;
    }

    int dec = number / 10;
    int uni = number % 10;

    int res = uni * 10 + dec;

    std::cout << res << std::endl;

    return 0;
}