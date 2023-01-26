#include <iostream>

int main() {
    int n = 0;
    int max = 0;
    int min = 0;
    int i = 1;

    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> n;

        if (n != -99) {
            if (i == 1) {
                max = min = n;
            }

            if (n > max) {
                max = n;
            }

            if (n < min) {
                min = n;
            }

            i++;
        } else {
            break;
        }
    }

    std::cout << "Max: " << max << std::endl;
    std::cout << "Min: " << min << std::endl;

    return 0;
}