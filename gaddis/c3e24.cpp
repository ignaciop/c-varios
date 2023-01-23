#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::cout << "Enter the angle in radians: ";
    double radians = 0.0;
    std::cin >> radians;

    double sinus = sin(radians);
    double cosinus = cos(radians);
    double tangent = tan(radians);

    std::cout << "sin(" << std::fixed << std::setprecision(4) << radians << ") = " << sinus << std::endl;
    std::cout << "cos(" << std::fixed << radians << ") = " << cosinus << std::endl;
    std::cout << "tan(" << std::fixed << radians << ") = " << tangent << std::endl;

    return 0;
}