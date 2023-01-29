#include "Coin.h"
#include <cstdlib>
#include <ctime>

Coin::Coin() {
    // Seed
    srand(time(NULL));

    // Random 0 or 1
    int value = rand() % 2;

    sideUp = ((value) ? "heads" : "tails");
}

Coin::~Coin() {}

std::string Coin::getSideUp() const {
    return sideUp;
}

void Coin::toss() {
    // Random 0 or 1
    int value = rand() % 2;

    sideUp = ((value) ? "heads" : "tails");
}