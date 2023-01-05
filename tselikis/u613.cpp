#include <iostream>

int main() {
    std::cout << "Enter an integer: ";
    int number = 0;
    std::cin >> number;

    int div = number;
    int rest = 0;
    int count = 1;

    while (div >= 2) {
        rest = div % 2;

        if (rest == 1) {
            count++;
        }

        div /= 2;
    }

    std::cout << "Bits set: " << count << std::endl;

    return 0;
}