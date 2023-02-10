#ifndef CYLINDER_H
#define CYLINDER_H

#include "Circle.h"

class Cylinder : public Circle {
    private:
        double height;
    public:
        Cylinder() = delete;
        Cylinder(double dRadius, double dHeight);
        Cylinder(const Cylinder& cylinderCopy);
        ~Cylinder();

        double getSurface() const;
        double getVolume() const;
};

#endif