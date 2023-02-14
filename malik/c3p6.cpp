#include <iostream>
#include <iomanip>

int main() {
    std::cout << "Enter the mass (in grams): ";
    double mass = 0.0;
    std::cin >> mass;

    std::cout << "Enter the density (in grams per cubic centimeter): ";
    double density = 0.0;
    std::cin >> density;

    double volume = mass / density;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Volume (cubic centimeters): " << volume << std::endl;

    return 0;
}