#include <iostream>

int main() {
    int n = 1;

    do {
        std::cout << "Enter a positive integer: ";
        std::cin >> n;
    } while (n <= 0);

    int total_terms = 0;
    float i = 5.0;
    float j = 3.0;
    float sum = 0.0;
    float term = 0.0;

    while (true) {
        if (sum <= n) {
            term = i / j;
            sum += term;

            total_terms++;

            i *= 5;
            j *= 3;
        } else {
            break;
        }
    };

    std::cout << "Last valid sum: " << sum << std::endl;
    std::cout << "Number of terms: " << total_terms << std::endl;
    
    return 0;
}