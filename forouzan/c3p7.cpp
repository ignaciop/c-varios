#include <iostream>

int main() {
    std::cout << "Enter the total number of hours: ";
    int total_hours = 0;
    std::cin >> total_hours;

    int weeks = total_hours / 168;
    int remaining_hours = total_hours % 168;

    int days = remaining_hours / 24;
    int hours = remaining_hours % 24;

    std::cout << total_hours << " hours is " << weeks << " weeks, "
                << days << " days and " << hours << " hours." << std::endl;
    
    return 0;
}