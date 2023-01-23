#include <iostream>

int main() {
    std::cout << "Number of vacation days: ";
    int days = 0;
    std::cin >> days;

    int hours = days * 24;
    int minutes = hours * 60;
    int seconds = minutes * 60;

    std::cout << days << " days is " << hours << " hours, " << minutes
                << " minutes and " << seconds << " seconds." << std::endl;

    return 0;
}