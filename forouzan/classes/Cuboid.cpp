#include "Cuboid.h"
#include <iostream>
#include <cassert>

Cuboid::Cuboid(double dLength, double dWidth, double dHeight) : Rectangle(dLength, dWidth), height(dHeight) {
    if (height < 0.0) {
        std::cout << "Cannot create a cuboid with negative height." << std::endl;
        std::cout << "The program will terminate." << std::endl;

        assert(false);
    }
}

Cuboid::Cuboid(const Cuboid& cuboidCopy) : Rectangle(cuboidCopy), height(cuboidCopy.height) {}
        
Cuboid::~Cuboid() {}

double Cuboid::getSurface() const {
    return (2 * (Rectangle::getArea() + Rectangle::getLength() * height + Rectangle::getWidth() * height));
}

double Cuboid::getVolume() const {
    return (Rectangle::getArea() * height);
}