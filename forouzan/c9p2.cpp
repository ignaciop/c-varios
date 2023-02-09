#include <iostream>
#include "classes/Fraction.h"

Fraction& larger(Fraction& fract1, Fraction& fract2);
Fraction& larger3(Fraction& fract1, Fraction& fract2, Fraction& fract3);

void largerR(Fraction& fract1, Fraction& fract2);
void largerR3(Fraction& fract1, Fraction& fract2, Fraction& fract3);

int main() {
    Fraction fract1(3, 2);
    Fraction fract2(6, 1);
    Fraction fract3(12, 5);

    std::cout << "Larger of the three fractions (pass-by-reference): " ;

    largerR3(fract1, fract2, fract3);
    fract1.print();

    Fraction fract4(3, 13);
    Fraction fract5(5, 17);
    Fraction fract6(1, 9);

    std::cout << "Larger of the three fractions (return-by-reference): " ;

    larger3(fract4, fract5, fract6).print();

    return 0;
}

Fraction& larger(Fraction& fract1, Fraction& fract2) {
    if (fract1.getNumer() * fract2.getDenom() > fract2.getNumer() * fract1.getDenom()) {
        return fract1;
    }

    return fract2;
}

Fraction& larger3(Fraction& fract1, Fraction& fract2, Fraction& fract3) {
    Fraction& f = larger(fract1, fract2);
    Fraction& g = larger(f, fract3);

    return g;
}

void largerR(Fraction& fract1, Fraction& fract2) {
    if (fract1.getNumer() * fract2.getDenom() > fract2.getNumer() * fract1.getDenom()) {
        fract2 = fract1;
    } else {
        fract1 = fract2;
    }
}

void largerR3(Fraction& fract1, Fraction& fract2, Fraction& fract3) {
    largerR(fract1, fract2);
    largerR(fract1, fract3);
}