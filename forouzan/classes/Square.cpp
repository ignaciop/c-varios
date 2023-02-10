#include "Square.h"
#include <iostream>
#include <cassert>

Square::Square(double dSide) : side(dSide) {
    if (side < 0.0) {
        std::cout << "Cannot create a square with negative side." << std::endl;
        std::cout << "The program will terminate." << std::endl;

        assert(false);
    }
}

Square::Square(const Square& squareCopy) : Square(squareCopy.side) {}

Square::~Square() {}

double Square::getPeri() const {
    return (4 * side);
}

double Square::getArea() const {
    return (side * side);
}