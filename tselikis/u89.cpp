#include <iostream>

int main() {
    int i = 0;
    int num = 0;
    int min = 0;
    int max = 0;
    int *p1 = &num;
    int *p2 = &min;
    int *p3 = &max;

    const int MAX_ENTRIES = 100;

    while (i < MAX_ENTRIES) {
        std::cout << "Enter integer number: ";
        std::cin >> num;

        if (*p1 < -5 && *p1 < *p2) {
            min = *p1;
        }

        if (*p1 > 10 && *p1 > *p3) {
            max = *p1;
        }

        if (*p1 >= -5 && *p1 <= 10) {
            std::cout << *p1 << " in [-5, 10]\n";
        }

        i++;
    }

    std::cout << "Min: " << *p2 << std::endl;
    std::cout << "Max: " << *p3 << std::endl;

    return 0;
}