#include <iostream>

int main() {
    std::cout << "Enter the total number of hours, minutes and seconds: ";
    int hours = 0, minutes = 0, seconds = 0;
    std::cin >> hours >> minutes >> seconds;

    int hours2seconds = hours * 60 * 60;
    int minutes2seconds = minutes * 60;

    int total_seconds = hours2seconds + minutes2seconds + seconds;

    std::cout << hours << " hours, " << minutes << " minutes and "
                << seconds << " seconds is " << total_seconds << " seconds." << std::endl;
    
    return 0;
}