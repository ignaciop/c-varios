#include <iostream>

const double PI = 3.1415;

int main() {
    double length, radius, area;

    std::cout << "Enter the length of the wire: ";
    std::cin >> length;

    radius = length / (2 * PI);
    area = PI * radius * radius;

    std::cout << "The radius of the circle is: " << radius << std::endl;
    std::cout << "The area of the circle is: " << area << std::endl;

    return 0;
}
