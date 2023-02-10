#ifndef CUBOID_H
#define CUBOID_H

#include "Rectangle.h"

class Cuboid : public Rectangle {
    private:
        double height;

    public:
        Cuboid() = delete;
        Cuboid(double dLength, double dWidth, double dHeight);
        Cuboid(const Cuboid& cuboidCopy);
        ~Cuboid();

        double getSurface() const;
        double getVolume() const;
};

#endif