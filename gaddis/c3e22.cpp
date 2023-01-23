#include <iostream>

int main() {
    const double PI = 3.14F;
    const double SLICE_AREA = 14.125F;

    std::cout << "Enter the diameter of the pizza (in inches): ";
    double diameter = 0.0;
    std::cin >> diameter;

    double radius = diameter / 2;
    double area = PI * radius * radius;
    double slices = area / SLICE_AREA;

    std::cout << "Number of slices: " << static_cast<int>(slices) << std::endl;

    return 0;
}