#include <iostream>
#include "classes/Circle.h"
#include "classes/Cylinder.h"

int main() {
    Circle c(1);
    Cylinder cy(3, 4);

    std::cout << "Circle perimeter: " << c.getPerimeter() << std::endl;
    std::cout << "Circle area: " << c.getArea() << std::endl;
    std::cout << "Cylinder surface: " << cy.getSurface() << std::endl;
    std::cout << "Cylinder volume: " << cy.getVolume() << std::endl;

    return 0;
}