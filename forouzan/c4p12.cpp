#include <iostream>

int main () {
    std::cout << "Enter a dollar value: ";
    int dollar = 0;
    std::cin >> dollar;

    int hundreds = dollar / 100;
    int remaining_dollars = dollar % 100;

    int fifties = remaining_dollars / 50;
    remaining_dollars %= 50;

    int twenties = remaining_dollars / 20;
    remaining_dollars %= 20;

    int tens = remaining_dollars / 10;
    remaining_dollars %= 10;

    int fives = remaining_dollars / 5;
    int ones = remaining_dollars % 5;

    (hundreds) ? (std::cout << "100 x " << hundreds << " = " << 100 * hundreds << std::endl) : (std::cout << " ");
    (fifties) ? (std::cout << "\n50 x " << fifties << " = " << 50 * fifties << std::endl) : (std::cout << " ");
    (twenties) ? (std::cout << "\n20 x " << twenties << " = " << 20 * twenties << std::endl) : (std::cout << " ");
    (tens) ? (std::cout << "    \n10 x " << tens << " = " << 10 * tens << std::endl) : (std::cout << " ");
    (fives) ? (std::cout << "    \n5 x " << fives << " = " << 5 * fives << std::endl) : (std::cout << " ");
    (ones) ? (std::cout << "     \n1 x " << ones << " = " << ones << std::endl) : (std::cout << " ");

    return 0;
}