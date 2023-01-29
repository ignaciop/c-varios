#include "Car.h"

int Car::getYear() const{
    return year;
}

std::string Car::getMake() const {
    return make;
}

int Car::getSpeed() const {
    return speed;
}

void Car::setSpeed(int inputSpeed) {
    speed = inputSpeed;
}
        
void Car::accelerate() {
    speed += 5;
}

void Car::brake() {
    if (speed > 0) {
        speed -= 5;
    } else {
        speed = 0;
    }
}