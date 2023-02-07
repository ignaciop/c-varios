#include "Two.h"

Two::Two() : Two(0, ' ') {}

Two::Two(int iX, char iA) : x(iX), a(iA) {}

Two::Two(const Two& twoCopy) : x(twoCopy.x), a(twoCopy.a) {}

Two::~Two() {}

int Two::getX() const {
    return x;
}

char Two::getA() const {
    return a;
}

void Two::setX(int iX) {
    x = iX;
}

void Two::setA(char ch) {
    a = ch;
}