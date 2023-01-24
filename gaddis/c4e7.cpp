#include <iostream>

int main() {
    std::cout << "Enter the number of seconds: ";
    double seconds = 0.0;
    std::cin >> seconds;

    if (seconds >= 86400) {
        std::cout << seconds << " seconds is " << seconds / 86400 << " days." << std::endl;
    }

    if (seconds < 86400 && seconds >= 3600) {
        std::cout << seconds << " seconds is " << seconds / 3600 << " hours." << std::endl;
    }

    if (seconds < 3600 && seconds >= 60) {
        std::cout << seconds << " seconds is " << seconds / 60 << " minutes." << std::endl;
    }
    
    return 0;
}