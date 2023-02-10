#include <iostream>
#include "classes/Circle.h"
#include "classes/Sphere.h"

int main() {
    Circle c(1);
    Sphere s(2.5);

    std::cout << "Circle perimeter: " << c.getPerimeter() << std::endl;
    std::cout << "Circle area: " << c.getArea() << std::endl;
    std::cout << "Sphere surface: " << s.getSurface() << std::endl;
    std::cout << "Sphere volume: " << s.getVolume() << std::endl;

    return 0;
}