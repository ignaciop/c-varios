#include <iostream>
#include "classes/Fraction.h"

Fraction& multiply(Fraction& fract1, Fraction& fract2);
void multiplyR(Fraction& fract1, Fraction& fract2);

int main() {
    Fraction fract1(3, 2);
    Fraction fract2(6, 5);

    std::cout << "Multiply (pass-by-reference): " ;

    multiplyR(fract1, fract2);
    fract1.print();

    Fraction fract4(3, 8);
    Fraction fract5(5, 7);

    std::cout << "Multiply (return-by-reference): " ;

    multiply(fract4, fract5).print();

    return 0;
}

Fraction& multiply(Fraction& fract1, Fraction& fract2) {
    fract1.setNumer(fract1.getNumer() * fract2.getNumer());
    fract1.setDenom(fract1.getDenom() * fract2.getDenom());

    return fract1;
}

void multiplyR(Fraction& fract1, Fraction& fract2) {
    fract1.setNumer(fract1.getNumer() * fract2.getNumer());
    fract1.setDenom(fract1.getDenom() * fract2.getDenom());
}