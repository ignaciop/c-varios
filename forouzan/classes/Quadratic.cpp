#include "Quadratic.h"
#include <iostream>
#include <cmath>

Quadratic::Quadratic() : Quadratic(1.0, 0.0, -1.0) {};
        
Quadratic::Quadratic(double iA, double iB, double iC) : a(iA), b(iB), c(iC) {}
        
Quadratic::Quadratic(const Quadratic& quadraticCopy) : a(quadraticCopy.a), b(quadraticCopy.b), c(quadraticCopy.c) {}

Quadratic::~Quadratic() {}

void Quadratic::print() const {
    std::cout << "\n" << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;
}

void Quadratic::roots() const {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        std::cout << "Root 1: " << (-b + sqrt(discriminant)) / (2 * a) << std::endl;
        std::cout << "Root 1: " << (-b - sqrt(discriminant)) / (2 * a) << std::endl;
    } else if (discriminant < 0) {
        std::cout << "The equation has no real roots" << std::endl;
    } else {
        std::cout << "Root 1 and 2: " << -b / (2 * a) << std::endl;
    }
}