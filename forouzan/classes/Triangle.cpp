#include "Triangle.h"
#include <iostream>
#include <cmath>
#include <cassert>

Triangle::Triangle() : Triangle(1.0, 1.0, 1.0) {}

Triangle::Triangle(double iFirstSide, double iSecondSide, double iThirdSide) {
    if (!sumSides(iFirstSide, iSecondSide, iThirdSide)) {
        std::cout << "No triangle can be made!" << std::endl;
        std::cout << "The program is aborted" << std::endl;

        assert(false);
    } else {
        firstSide = iFirstSide;
        secondSide = iSecondSide;
        thirdSide = iThirdSide;
    }
}

Triangle::Triangle(const Triangle& triangleCopy) : firstSide(triangleCopy.firstSide), secondSide(triangleCopy.secondSide), thirdSide(triangleCopy.thirdSide) {}
        
Triangle::~Triangle() {}

void Triangle::getSides(double& fs, double& ss, double& ts) const {
    fs = firstSide;
    ss = secondSide;
    ts = thirdSide;
}

double Triangle::getPerimeter() const {
    return (firstSide + secondSide + thirdSide);
}

double Triangle::getArea() const {
    double p = getPerimeter() / 2;
    double area = sqrt(p * (p - firstSide) * (p - secondSide) * (p - thirdSide));

    return area;
}

bool Triangle::sumSides(double iFirstSide, double iSecondSide, double iThirdSide) {
    bool sumGT = (iFirstSide + iSecondSide > iThirdSide) || (iFirstSide + iThirdSide > iSecondSide) || (iSecondSide + iThirdSide > iFirstSide);

    return sumGT;
}