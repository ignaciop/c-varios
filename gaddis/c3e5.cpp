#include <iostream>
#include <iomanip>

int main() {
    std::cout << "Number of times the player was at bat: ";
    int bat_times = 0;
    std::cin >> bat_times;

    std::cout << "Number of hits earned: ";
    int hits = 0;
    std::cin >> hits;

    double batting_avg = static_cast<double>(hits) / bat_times;

    std::cout << "Batting average: " << std::fixed << std::setprecision(3)
                << batting_avg << std::endl;

    return 0;
}