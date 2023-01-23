#include <iostream>

int main() {
    std::cout << "Enter temperature (Celsius): ";
    double celsius = 0.0;
    std::cin >> celsius;

    double fahrenheit = (9 / 5) * celsius + 32;

    std::cout << celsius << "ºC is " << fahrenheit << "ºF." << std::endl;

    return 0;
}