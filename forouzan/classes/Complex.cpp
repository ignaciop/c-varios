#include "Complex.h"
#include <iostream>
#include <cmath>

Complex::Complex(): Complex(1.0, 0.0) {}

Complex::Complex(double iX, double iY) : x(iX), y(iY) {}

Complex::Complex(const Complex& complexCopy) : x(complexCopy.x), y(complexCopy.y) {} 

Complex::~Complex() {}

Complex Complex::add(const Complex& otherComplex) {
    Complex res(x + otherComplex.x, y + otherComplex.y);

    return res;
}

Complex Complex::substract(const Complex& otherComplex) {
    Complex res(x - otherComplex.x, y - otherComplex.y);

    return res;
}

Complex Complex::multiply(const Complex& otherComplex) {
    double resx = x * otherComplex.x - y * otherComplex.y;
    double resy = x * otherComplex.y + y * otherComplex.x;

    Complex res(resx, resy);

    return res;
}

Complex Complex::divide(const Complex& otherComplex) {
    double denominator = otherComplex.x * otherComplex.x + otherComplex.y + otherComplex.y;

    Complex res;

    if (denominator != 0.0) {
        double resx = x * otherComplex.x + y * otherComplex.y;
        double resy = -x * otherComplex.y + y * otherComplex.x;

        res.x = resx / denominator;
        res.y = resy / denominator;
    } else {
        std::cout << "Cannot divide by zero. Result default to Complex(1.0, 0.0)" << std::endl;
    }

    return res;
}

void Complex::print() const {
    if (y >= 0) {
       std::cout << x << " + " << y << "i" << std::endl;
    } else {
       std::cout << x << " - " << fabs(y) << "i" << std::endl;
    }
}