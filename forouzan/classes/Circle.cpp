#include "Circle.h"
#include <iostream>
#include <cassert>

Circle::Circle(double dRadius) : radius(dRadius) {
    if (radius < 0.0) {
        std::cout << "Cannot create a circle with negative radius." << std::endl;
        std::cout << "The program will terminate." << std::endl;

        assert(false);
    }
}

Circle::Circle(const Circle& circleCopy) : Circle(circleCopy.radius) {}
        
Circle::~Circle() {}

double Circle::getPerimeter() const {
    const double PI = 3.1415F;

    return (2 * PI * radius);
}

double Circle::getArea() const {
    const double PI = 3.1415F;

    return (PI * radius * radius);
}