#include <iostream>
#include "classes/Complex.h"

int main() {
    Complex c1;
    Complex c2(2.5, -2);
    Complex c3(c1);
    Complex c4(0.0, 1.0);

    c1.print();
    c2.print();
    c3.print();
    c4.print();

    Complex c5(c1.add(c2));
    Complex c6(c2.substract(c3));
    Complex c7(c3.multiply(c2));
    Complex c8(c4.divide(c1));

    c5.print();
    c6.print();
    c7.print();
    c8.print();

    return 0;
}