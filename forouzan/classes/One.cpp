#include "One.h"

One::One() : One(0, 0) {}

One::One(int iX, int iY) : x(iX), y(iY) {}

One::One(const One& oneCopy) : x(oneCopy.x), y(oneCopy.y) {}

One::~One() {}

int One::getX() const {
    return x;
}

int One::getY() const {
    return y;
}