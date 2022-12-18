#include <iostream>

int main() {
    enum YourCards {Ace, Jack, Queen = 45, King};

    std::cout << YourCards::Queen << std::endl;

    return 0;
}
