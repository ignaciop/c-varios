#include <iostream>
#include "classes/Coin.h"

int main() {
    Coin c;

    std::cout << "Coin initial side: " << c.getSideUp() << std::endl;

    int total_heads = 0;
    int total_tails = 0;

    for (int i = 1; i <= 20; i++) {
        c.toss();

        std::string side = c.getSideUp();

        std::cout << "Coin side: " << side << std::endl;

        if (side == "heads") {
            total_heads++;
        } else {
            total_tails++;
        }
    }

    std::cout << "Number of heads: " << total_heads << std::endl;
    std::cout << "Number of tails: " << total_tails << std::endl;

    return 0;
}