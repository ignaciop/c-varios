#include "Dice.h"
#include <cstdlib>
#include <ctime>

 Dice::Dice(int iValue) {
    srand(time(NULL));

    sides = iValue;
    roll();
 }
        
Dice::~Dice() {}

int Dice::getSides() const {
    return sides;
}

int Dice::getValue() const{
    return value;
}

void Dice::roll() {
    const int MIN_VALUE = 1;

    value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;
}