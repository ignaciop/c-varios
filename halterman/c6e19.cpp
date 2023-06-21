#include <iostream>

int main() {
    const int MAX_N = 20;

    double sum {}, avg {}, max {0}, min {0};
    
    int i {1};

    while (i <= MAX_N) {
        std::cout << i << ". Number? ";
        double n {};
        std::cin >> n;

        sum += n;

        if (max <= n) {
            max = n;
        }

        if (min >= n) {
            min = n;
        }

        i++;
    }

    avg = sum / MAX_N;

    std::cout << "Total sum: " << sum << std::endl;
    std::cout << "Average  : " << avg << std::endl;
    std::cout << "Maximum  : " << max << std::endl;
    std::cout << "Minimum  : " << min << std::endl;

    return 0;
}