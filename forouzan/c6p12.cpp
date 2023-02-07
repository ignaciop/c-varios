#include <iostream>

double celsiusToFahrenheit(double c);

int main () {
    std::cout << "  0ºC ---> " << celsiusToFahrenheit(0) << "ºF" << std::endl;
    std::cout << " 37ºC ---> " << celsiusToFahrenheit(37) << "ºF" << std::endl;
    std::cout << " 40ºC ---> " << celsiusToFahrenheit(40) << "ºF" << std::endl;
    std::cout << "100ºC ---> " << celsiusToFahrenheit(100) << "ºF" << std::endl;

    return 0;
}

double celsiusToFahrenheit(double c) {
    return (c * 180.0F / 100.0F + 32);
}