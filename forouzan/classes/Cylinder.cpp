#include "Cylinder.h"
#include <iostream>
#include <cassert>
#include <cmath>

Cylinder::Cylinder(double dRadius, double dHeight) : Circle(dRadius), height(dHeight) {
    if (height < 0.0) {
        std::cout << "Cannot create a cylinder with negative height." << std::endl;
        std::cout << "The program will terminate." << std::endl;

        assert(false);
    }
}

Cylinder::Cylinder(const Cylinder& cylinderCopy) : Circle(cylinderCopy), height(cylinderCopy.height) {}

Cylinder::~Cylinder() {}

double Cylinder::getSurface() const {
    double perimeter = Circle::getPerimeter();

    return (height * perimeter);
}

double Cylinder::getVolume() const {
    
    double area = Circle::getArea();

    return (height * area);
}