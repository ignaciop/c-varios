#include "Point2.h"
#include <iostream>
#include <cmath>

Point::Point() : Point(0.0, 0.0) {}
        
Point::Point(int iX, int iY) : x(iX), y(iY) {}

Point::Point(const Point& pointCopy) : x(pointCopy.x), y(pointCopy.y) {}

Point::~Point() {}

void Point::print() {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}
        
double Point::distance(const Point& otherPoint) {
    double d = sqrt(pow(x - otherPoint.x, 2) + pow(y - otherPoint.y, 2));

    return d;
}