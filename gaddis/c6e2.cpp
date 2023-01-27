#include <iostream>
#include <iomanip>

double celsius(double fahrenheit);

int main() {
    const int MAX_TEMP = 100;

    std::cout << "Fahrenheit" << std::setw(13) << "Celsius" << std::endl;
    std::cout << "-------------------------" << std::endl;

    for (int i = 0; i <= MAX_TEMP; i += 5) {
        double f = celsius(i);

        std::cout << std::setw(6) << i << std::right << std::setw(17)
                    << std::fixed << std::setprecision(2) << f << std::endl;
    }

    return 0;
}

double celsius(double fahrenheit) {
    return ((5.0 / 9) * (fahrenheit - 32));
}