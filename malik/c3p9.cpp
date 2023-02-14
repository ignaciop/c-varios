#include <iostream>
#include <cmath>

const double PI = 3.1415;

int main() {
    std::cout << "Enter the cylinder radius: ";
    double radius = 0.0;
    std::cin >> radius;

    std::cout << "Enter the cylinder height: ";
    double height = 0.0;
    std::cin >> height;

    double volume_c = PI * radius * radius * height;
    double cube_side = pow(volume_c, 1.0 / 3);

    std::cout << "The cube must have a side of " << cube_side 
                << " to preserve the cylinder volume" << std::endl;

    return 0;
}