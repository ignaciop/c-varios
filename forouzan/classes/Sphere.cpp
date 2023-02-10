#include "Sphere.h"
#include <iostream>
#include <cassert>
#include <cmath>

Sphere::Sphere(double dRadius) : Circle(dRadius) {}

Sphere::Sphere(const Sphere& sphereCopy) : Circle(sphereCopy) {}

Sphere::~Sphere() {}

double Sphere::getSurface() const {
    const double PI = 3.1415F;

    double area = Circle::getArea();
    double radius = sqrt(area / PI);
    double perimeter = Circle::getPerimeter();

    return (2 * radius * perimeter);
}

double Sphere::getVolume() const {
    const double PI = 3.1415F;
    
    double area = Circle::getArea();
    double radius = sqrt(area / PI);

    return (4.0F / 3 * radius * area);
}