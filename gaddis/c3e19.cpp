#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main() {
    const int LL = 1;
    const int UL = 9;

    // Seed
    srand(time(NULL));

    // Random numbers between [LL, UL]
    int num1 = LL + (rand() % (UL - LL + 1));
    int num2 = LL + (rand() % (UL - LL + 1));
    int res = num1 + num2;

    std::cout << std::setw(2) << num1 << "\n+" << std::setw(1) << num2 << "\n---" << std::endl;

    std::cout << "Enter answer: ";
    int ans = 0;
    std::cin >> ans;

    std::cout << "The correct answer is: " << res << std::endl;

    return 0;
}