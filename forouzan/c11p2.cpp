#include <iostream>
#include "classes/Rectangle.h"
#include "classes/Cuboid.h"

int main() {
    Rectangle r(2.5, 3.5);
    Cuboid c(1, 2, 3);

    std::cout << "Rectangle perimeter: " << r.getPeri() << std::endl;
    std::cout << "Rectangle area: " << r.getArea() << std::endl;
    std::cout << "Cuboid surface: " << c.getSurface() << std::endl;
    std::cout << "Cuboid volume: " << c.getVolume() << std::endl;

    return 0;
}