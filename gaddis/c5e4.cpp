#include <iostream>
#include <iomanip>

int main() {
    const int MAX_TEMP = 30;

    std::cout << "\nCelsius (ºC)\tFahrenheit (ºF)" << std::endl;
    std::cout << "-------------------------------" << std::endl;

    for (int i = 0; i <= MAX_TEMP; i++) {
        double f = (9.0 / 5) * i + 32;

        std::cout << std::setw(5) << i << "\t" << std::setw(15) << f << std::endl;
    }

    return 0;
}