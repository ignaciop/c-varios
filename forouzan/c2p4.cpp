#include <iostream>

int main() {
    std::cout << "Enter the task duration in hours, minutes and seconds: " << std::endl;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    std::cin >> hours >> minutes >> seconds;

    int hours2seconds = hours * 60 * 60;
    int minutes2seconds = minutes * 60;

    int total_seconds = hours2seconds + minutes2seconds + seconds;

    std::cout << "Total seconds: " << total_seconds << std::endl;

    return 0;
}