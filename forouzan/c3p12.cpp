#include <iostream>

int main() {
    std::cout << "Enter a temperature in Celsius: ";
    double celsius = 0.0;
    std::cin >> celsius;

    double fahrenheit = (9.0F / 5) * celsius + 32;

    std::cout << celsius << "ºC is " << fahrenheit << "ºF." << std::endl;

    return 0;
}