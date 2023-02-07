#include "Point.h"
#include <iostream>
#include <cmath>

Point::Point() : Point(0.0, 0.0) {}
        
Point::Point(int iX, int iY) : x(iX), y(iY) {}

Point::Point(const Point& pointCopy) : x(pointCopy.x), y(pointCopy.y) {}

Point::~Point() {}

void Point::print() {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}
        
void Point::location(const Point& otherPoint) {
    if (x > otherPoint.x) {
        std::cout << "Right ";
    } else if (x < otherPoint.x) {
        std::cout << "Left ";
    } else {
        std::cout << "";
    }

    if (y > otherPoint.y) {
        std::cout << "Above" << std::endl;
    } else if (y < otherPoint.y) {
        std::cout << "Under" << std::endl;
    } else {
        std::cout << "" << std::endl;
    }
}
        
double Point::distance(const Point& otherPoint) {
    double d = sqrt(pow(x - otherPoint.x, 2) + pow(y - otherPoint.y, 2));

    return d;
}