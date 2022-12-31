#include <iostream>

int main() {
    std::cout << "Enter three integers: ";
    int i, j, k;
    std::cin >> i >> j >> k;

    if (i + j == k || i + k == j || j + k == i) {
        std::cout << "1 2 3 4 5 6 7 8 9 10" << std::endl;
    } else {
        std::cout << "Enter another three integers: ";
        int l, m, n;
        std::cin >> l >> m >> n;

        int count = 0;

        if (l % 6 == 0) {
            count++;
        }

        if (m % 6 == 0) {
            count++;
        }

        if (n % 6 == 0) {
            count++;
        }

        std::cout << count << std::endl;
    }
    
    return 0;
}