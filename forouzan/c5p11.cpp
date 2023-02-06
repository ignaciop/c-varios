#include <iostream>

int main () {
    int n = 1;
    int max = 0;
    int min = 0;

    do {
        std::cout << "Enter the number of scores: ";
        std::cin >> n;
    } while (n < 1 || n > 10);

    for (int i = 1; i <= n; i++) {
        int m = 0;

        do {
            std::cout << "Enter a score between 0 and 100: ";
            std::cin >> m;
        } while (m < 0 || m > 100);

        if (i == 1) {
            max = min = m;
        }

        if (max < m) {
            max = m;
        }

        if (min > m) {
            min = m;
        }
    }

    std::cout << "Smallest score: " << min << std::endl;
    std::cout << "Largest score: " << max << std::endl;

    return 0;
}