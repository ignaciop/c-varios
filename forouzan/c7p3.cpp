#include <iostream>
#include "classes/Point.h"

int main() {
    Point q1(1, 2);
    Point q2(-1, 2);
    Point q3(-1, -2);
    Point q4(1, -2);

    std::cout << "Points: " << std::endl;
    q1.print();
    q2.print();
    q3.print();
    q4.print();

    std::cout << "\nDistances: " << std::endl;
    std::cout << "Between 1 and 2: " << q1.distance(q2) << std::endl;
    std::cout << "Between 3 and 4: " << q3.distance(q4) << std::endl;

    std::cout << "\nLocations: " << std::endl;
    std::cout << "q1 respect to q2: ";
    q1.location(q2);

    std::cout << "q2 respect to q3: ";
    q2.location(q3);

    std::cout << "q3 respect to q4: ";
    q3.location(q4);

    std::cout << "q4 respect to q1: ";
    q4.location(q1);

    Point q5(q1);

    std::cout << "\nCopy Point: " << std::endl;
    q5.print();

    return 0;
}