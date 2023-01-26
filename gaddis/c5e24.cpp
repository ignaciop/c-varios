#include <iostream>

int main() {
    const int UNIT = 100;

    std::cout << "Enter today's sales for store 1: ";
    double s1 = 0.0;
    std::cin >> s1;

    std::cout << "Enter today's sales for store 2: ";
    double s2 = 0.0;
    std::cin >> s2;

    std::cout << "Enter today's sales for store 3: ";
    double s3 = 0.0;
    std::cin >> s3;

    int i1 = static_cast<int>(s1) / UNIT;
    int i2 = static_cast<int>(s2) / UNIT;
    int i3 = static_cast<int>(s3) / UNIT;

    std::cout << "   DAILY SALES" << std::endl;
    std::cout << " (each * = $100)" << std::endl;

    std::cout << "Store 1: ";

    for (int i = 1; i <= i1; i++) {
        std::cout << '*';
    }

    std::cout << "\nStore 2: ";

    for (int i = 1; i <= i2; i++) {
        std::cout << '*';
    }

    std::cout << "\nStore 3: ";

    for (int i = 1; i <= i3; i++) {
        std::cout << '*';
    }

    std::cout << '\n';

    return 0;
}