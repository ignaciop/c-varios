#include <iostream>
#include <cstdlib>
#include <ctime>

int main () {
    const int LL = 10;
    const int UL = 99;

    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;

    // Seed
    srand(time(0));

    int rn = 0;

    for (int i = 1; i <= 10; i++) {
        rn = LL + (rand() % (UL - LL + 1));
        sum1 += rn;

        rn = LL + (rand() % (UL - LL + 1));
        sum2 += rn;

        rn = LL + (rand() % (UL - LL + 1));
        sum3 += rn;

        rn = LL + (rand() % (UL - LL + 1));
        sum4 += rn;

        rn = LL + (rand() % (UL - LL + 1));
        sum5 += rn;
    }

    std::cout << "Sum of set1: " << sum1 << std::endl;
    std::cout << "Sum of set2: " << sum2 << std::endl;
    std::cout << "Sum of set3: " << sum3 << std::endl;
    std::cout << "Sum of set4: " << sum4 << std::endl;
    std::cout << "Sum of set5: " << sum5 << std::endl;

    return 0;
}