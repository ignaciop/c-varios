#include <iostream>
#include "classes/Coin.h"

int main() {
    const double ONE_DOLLAR = 1.0F;

    Coin quarter;
    Coin dime;
    Coin nickel;

    double balance = 0.0;

    while (balance < ONE_DOLLAR) {
        quarter.toss();
        dime.toss();
        nickel.toss();

        double quarterValue = ((quarter.getSideUp() == "heads") ? 0.25 : 0.0);
        double dimeValue = ((dime.getSideUp() == "heads") ? 0.10 : 0.0);
        double nickelValue = ((nickel.getSideUp() == "heads") ? 0.05 : 0.0);

        balance += quarterValue + dimeValue + nickelValue;
    }

    if (balance == ONE_DOLLAR) {
        std::cout << "Congratulations, you won the game!" << std::endl;
    } else {
        std::cout << "Sorry, you lost." << std::endl;
    }

    return 0;
}