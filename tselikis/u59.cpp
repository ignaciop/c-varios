#include <iostream>

int main() {
    std::cout << "Enter a four-digit positive integer: ";
    unsigned int number;
    std::cin >> number;

    unsigned int first_digit = number / 1000;
    unsigned int rest = number % 1000;

    unsigned int second_digit = rest / 100;
    rest %= 100;

    unsigned int third_digit = rest / 10;
    unsigned int fourth_digit = rest % 10;

    std::cout << ((first_digit == fourth_digit && second_digit == third_digit) ? "Yes!" : "No" ) << std::endl;

    return 0;
}