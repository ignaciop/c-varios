#include <iostream>
#include "classes/Car.h"

int main() {
    Car c(2020, "Porsche");

    for (int i = 1; i <= 5; i++) {
        c.accelerate();

        std::cout << "Speed: " << c.getSpeed() << " km/h" << std::endl;
    }

    for (int i = 1; i <= 5; i++) {
        c.brake();

        std::cout << "Speed: " << c.getSpeed() << " km/h" << std::endl;
    }

    return 0;
}