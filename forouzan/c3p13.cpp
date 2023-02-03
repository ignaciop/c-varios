#include <iostream>

int main() {
    std::cout << "Enter a temperature in Fahrenheit: ";
    double fahrenheit = 0.0;
    std::cin >> fahrenheit;

    double celsius = (fahrenheit - 32) * 5.0F / 9;

    std::cout << fahrenheit << "ºF is " << celsius << "ºC." << std::endl;

    return 0;
}