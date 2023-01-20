#include <iostream>

int minimum(int a, int b);

int main() {
    std::cout << "Enter first number: ";
    int a = 0;
    std::cin >> a;

    int b = 0;

    do {
        std::cout << "Enter second number (greater than first): ";
        std::cin >> b;
    } while (a >= b);

    int res = minimum(a, b);
    
    std::cout << "\nMinimum entered in [" << a << ", " << b << "] = "
                << res << std::endl;

    return 0;
}

int minimum(int a, int b) {
    int min = a;

    for (int i = 1; i <= 100; i++) {
        int n = 0;
        std::cout << "Enter a number: ";
        std::cin >> n;

        if (i == 1) {
            min = n;
        } else {
            if (n >= a && n <= b) {
                if (n < min) {
                    min = n;
                }
            }
        }
    }

    return min;
}
