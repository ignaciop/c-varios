#include <iostream>
#include "classes/Point2.h"

int main() {
    Point p(1, 1);
    Point q(3.5, -2.1);

    double distance = p.distance(q);

    p.print();
    q.print();
    std::cout << "Distance: " << distance << std::endl;

    return 0;
}