#include <iostream>
#include "classes/Zeller.h"

int main() {
    Zeller z1;
    z1.weekday();

    Zeller z2(31, 12, 2012);
    z2.weekday();

    Zeller z3(z2);
    z3.weekday();

    return 0;
}