#include <iostream>

float celsiusToFahrenheit(float celsius);

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5 + 32);
}

int main() {
    float celsius;

    std::cout << "Enter a temperature in Celsius: ";
    std::cin >> celsius;

    float fahrenheit = celsiusToFahrenheit(celsius);

    std::cout << celsius << "ºC is " << fahrenheit << "ºF." << std::endl;

    return 0;
}