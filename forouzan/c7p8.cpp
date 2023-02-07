#include <iostream>
#include "classes/Quadratic.h"

int main() {
    Quadratic q1;
    q1.print();
    q1.roots();

    Quadratic q2(1.0, 0.0, 1.0);
    q2.print();
    q2.roots();

    Quadratic q3(1.0, 2.0, 1.0);
    q3.print();
    q3.roots();

    return 0;
}