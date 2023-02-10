#ifndef SPHERE_H
#define SPHERE_H

#include "Circle.h"

class Sphere : public Circle {
    public:
        Sphere() = delete;
        Sphere(double dRadius);
        Sphere(const Sphere& sphereCopy);
        ~Sphere();

        double getSurface() const;
        double getVolume() const;
};

#endif