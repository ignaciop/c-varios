#include <iostream>

int main() {
    const double TV_COST = 1400.0F;
    const double DVD_COST = 220.0F;
    const double REMOTE_COST = 35.20F;
    const double TAX = 0.0825F;

    std::cout << "How many tv's you have purchased? ";
    int tvs = 0;
    std::cin >> tvs;

    std::cout << "How many dvd's you have purchased? ";
    int dvds = 0;
    std::cin >> dvds;

    std::cout << "How many remotes you have purchased? ";
    int remotes = 0;
    std::cin >> remotes;

    double tv_cost = tvs * TV_COST;
    double dvd_cost = dvds * DVD_COST;
    double remote_cost = remotes * REMOTE_COST;

    double subtotal = tv_cost + dvd_cost + remote_cost;
    double total = subtotal + (subtotal * TAX);
   
    std::cout << "Qty\tPrice per qty ($)\tTotal price ($)" << std::endl;
    std::cout << tvs << "\t" << TV_COST << "\t\t\t" << tv_cost << std::endl;
    std::cout << dvds << "\t" << DVD_COST << "\t\t\t" << dvd_cost << std::endl;
    std::cout << remotes << "\t" << REMOTE_COST << "\t\t\t" << remote_cost << std::endl;
    std::cout << "\nSubtotal: $" << subtotal << std::endl;
    std::cout << "Tax:        " << TAX * 100 << "%" << std::endl;
    std::cout << "\nTotal:    $" << total << std::endl;

    return 0;
}