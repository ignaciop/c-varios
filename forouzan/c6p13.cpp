#include <iostream>

double fahrenheitToCelsius(double f);

int main () {
    std::cout << "  32ºF   ---> " << fahrenheitToCelsius(0) << "ºC" << std::endl;
    std::cout << "  98.6ºF ---> " << fahrenheitToCelsius(98.6) << "ºC" << std::endl;
    std::cout << " 104ºF   ---> " << fahrenheitToCelsius(104) << "ºC" << std::endl;
    std::cout << " 212ºF   ---> " << fahrenheitToCelsius(212) << "ºC" << std::endl;

    return 0;
}

double fahrenheitToCelsius(double f) {
    return ((f - 32) * (100.0F / 180.0F));
}