#include <iostream>
#include <iomanip>

int main () {
    for (int celsius = 0; celsius <= 99; celsius++) {
        double fahrenheit = celsius * 180.0F / 100.0F + 32;

        std::cout << std::setw(2) << celsius << "ºC ---> " << std::setw(5) 
                    << std::fixed << std::setprecision(1) << fahrenheit 
                    << "ºF" << std::endl;
    }

    return 0;
}