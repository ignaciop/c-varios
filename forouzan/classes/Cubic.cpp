#include "Cubic.h"
#include <cmath>

Cubic::Cubic(double dSide) : Square(dSide) {}

Cubic::Cubic(const Cubic& cubicCopy) : Square(cubicCopy) {}
        
Cubic::~Cubic() {}

double Cubic::getArea() const {
    return (Square::getArea() * 6);
}

double Cubic::getVolume() const {
    return (pow(Square::getArea(), 1.5));
}