#ifndef CUBIC_H
#define CUBIC_H

#include "Square.h"

class Cubic : public Square {
    public:
        Cubic() = delete;
        Cubic(double dSide);
        Cubic(const Cubic& cubicCopy);
        ~Cubic();

        double getArea() const;
        double getVolume() const;
};

#endif