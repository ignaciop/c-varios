#include <iostream>
#include "classes/Square.h"
#include "classes/Cubic.h"

int main() {
    Square square(5);
    Cubic cubic(7);
    Cubic cubic2(8);
    Cubic cubicCopy(cubic2);

    std::cout << "Perimeter of square: " << square.getPeri() << std::endl;
    std::cout << "Area of square: " << square.getArea() << std::endl;
    std::cout << "Area of cube: " << cubic.getArea() << std::endl;
    std::cout << "Volume of cube: " << cubic.getVolume() << std::endl;
    std::cout << "Area of copy cube: " << cubicCopy.getArea() << std::endl;
    std::cout << "Volume of copy cube: " << cubicCopy.getVolume() << std::endl;
    
    return 0;
}