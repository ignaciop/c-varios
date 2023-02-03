#include <iostream>

int main() {
    std::cout << "Enter the total number of seconds: ";
    int total_seconds = 0;
    std::cin >> total_seconds;
    
    int days = total_seconds / 86400;
    int remaining_seconds = total_seconds % 86400;

    int hours = remaining_seconds / 3600;
    remaining_seconds %= 3600;

    int minutes = remaining_seconds / 60;
    int seconds = remaining_seconds % 60;

    std::cout << total_seconds << " seconds is " << days << " days, "
                << hours << " hours, " << minutes << " minutes and "
                    << seconds << " seconds." << std::endl;
    
    return 0;
}