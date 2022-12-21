#include <iostream>

void Calculate(double radius, double &Area, double &Circumference);

int main() {
    std::cout << "Enter radius: ";
    double radius;
    std::cin >> radius;

    double Area;
    double Circumference;

    Calculate(radius, Area, Circumference);

    std::cout << "Area: " << Area << std::endl;
    std::cout << "Circumference: " << Circumference << std::endl;

    return 0;
}

void Calculate(double radius, double &Area, double &Circumference) {
    Area = 3.14 * radius * radius;
    Circumference = 2 * 3.14 * radius;
}