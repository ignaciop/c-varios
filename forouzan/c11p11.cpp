#include <iostream>
#include "classes/Fraction2.h"

int main() {
    Fraction f(1, 2);
    Fraction g(3, 4);

    Fraction r1(f.add(g));
    Fraction r2(f.substract(g));
    Fraction r3(f.multiply(g));
    Fraction r4(f.divide(g));

    std::cout << "Add      : " << r1.getNumer() << "/" << r1.getDenom() << std::endl;
    std::cout << "Substract: " << r2.getNumer() << "/" << r2.getDenom() << std::endl;
    std::cout << "Multiply : " << r3.getNumer() << "/" << r3.getDenom() << std::endl;
    std::cout << "Divide   : " << r4.getNumer() << "/" << r4.getDenom() << std::endl;

    return 0;
}