#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main() {
    const int LL = 10;
    const int UL = 50;

    // Seed
    srand(time(NULL));

    // Random numbers between [LL, UL]
    int num1 = LL + (rand() % (UL - LL + 1));
    int num2 = LL + (rand() % (UL - LL + 1));
    int res = num1 + num2;

    std::cout << std::setw(3) << num1 << "\n+" << std::setw(1) << num2 << "\n---" << std::endl;

    std::cout << "Enter answer: ";
    int ans = 0;
    std::cin >> ans;

    if (ans == res) {
        std::cout << "Congratulations! Your answer is correct." << std::endl;
    } else {
        std::cout << "Sorry, your answer is incorrect. The right answer is "
                    << res << std::endl;
    }

    return 0;
}