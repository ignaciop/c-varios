#include <iostream>

int main() {
    int n = 2;
    int prime_flag = 1;

    do {
        std::cout << "Enter an integer > 1: ";
        std::cin >> n;
    } while (n <= 1);

    std::cout << "Prime numbers less than or equal to " << n << ": ";

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                prime_flag = 0;
                break;
            }
        }

        if (prime_flag) {
            std::cout << i << " ";
        }

        prime_flag = 1;
    }

    std::cout << std::endl;
    
    return 0;
}