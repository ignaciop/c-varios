#include <iostream>

int main() {
    int n = 0;
    int max = 0;
    int min = 0;
    int positive_count = 0;
    int negative_count = 0;
    int total = 0;

    while (true) {
        std::cout << "Enter an integer (0 to stop insertion): ";
        std::cin >> n;

        if (total == 0) {
            max = min = n;
        }

        if (n != 0) {
            total++;

            if (n > 0) {
                positive_count++;
            }
        
            if (n < 0) {
                negative_count++;
            }

            if (n > max) {
                max = n;
            }

            if (n < min) {
                min = n;
            }
        } else {
            break;
        }
    }

    if (total == positive_count) {
        std::cout << "All numbers entered were positive." << std::endl;
    }

    if (total == negative_count) {
        std::cout << "All numbers entered were negative." << std::endl;
    }

    std::cout << "Maximum number: " << max << std::endl;
    std::cout << "Minimum number: " << min << std::endl;

    return 0;
}