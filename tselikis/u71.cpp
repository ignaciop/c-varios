#include <iostream>

int main() {
    const int ARR_SIZE = 100;
    float grades[ARR_SIZE] = {};
    float grade = 0.0;
    float a, b = 0.0;
    int count = 0;

    for (int i = 0; i < ARR_SIZE; i++) {
        std::cout << "Enter grade: ";
        std::cin >> grade;

        grades[i] = grade;
    }

    std::cout << std::endl;

    do {
        std::cout << "Enter lower range of grades: ";
        std::cin >> a;

        std::cout << "Enter higher range of grades: ";
        std::cin >> b;
    } while (b <= a);

    for (int i = 0; i < ARR_SIZE; i++) {
        if (a <= grades[i] && grades[i] <= b) {
            count++;
        }
    }

    std::cout << std::endl;

    std::cout << count << " students got a grade within [" << a << ", " << b << "]" << std::endl; 

    return 0;
}