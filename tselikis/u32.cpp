#include <iostream>

int main() {
    std::cout << "Enter number of plates: ";
    int plates = 0;
    std::cin >> plates;

    std::cout << "Enter price per plate: ";
    float price_per_plate = 0.0;
    std::cin >> price_per_plate;

    std::cout << "Enter number of cups: ";
    int cups = 0;
    std::cin >> cups;

    std::cout << "Enter price per cup: ";
    float price_per_cup = 0.0;
    std::cin >> price_per_cup;

    std::cout << "Enter what you paid: ";
    float paid = 0.0;
    std::cin >> paid;

    float change = paid - ((plates * price_per_plate) + (cups * price_per_cup));

    std::cout << "Change: " << change << std::endl;

    return 0;
}