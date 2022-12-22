#include <iostream>

#define MULTIPLY(X, Y) (X * Y)

int main() {
    std::cout << "Enter an integer number: ";
    int number1;
    std::cin >> number1;

    std::cout << "Enter another integer number: ";
    int number2;
    std::cin >> number2;

    std::cout << number1 << " * " << number2 << " = "
                << MULTIPLY(number1, number2) << std::endl;
      
    return 0;
}

