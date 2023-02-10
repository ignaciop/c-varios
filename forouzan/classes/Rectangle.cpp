#include "Rectangle.h"
#include <iostream>
#include <cassert>

Rectangle::Rectangle(double dLength, double dWidth) : length(dLength), width(dWidth) {
    if (length < 0.0 || width < 0.0) {
        std::cout << "Cannot create a rectangle with negative length or width." << std::endl;
        std::cout << "The program will terminate." << std::endl;

        assert(false);
    }
}

Rectangle::Rectangle(const Rectangle& rectangleCopy) : Rectangle(rectangleCopy.length, rectangleCopy.width) {}

Rectangle::~Rectangle() {}

double Rectangle::getLength() const {
    return length;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getPeri() const {
    return (2 * (length + width));
}

double Rectangle::getArea() const {
    return (length * width);
}