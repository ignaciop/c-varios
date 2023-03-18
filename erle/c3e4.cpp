#include <iostream>

int main() {
    std::cout << "Enter an integer number: ";
    int x {};
    std::cin >> x;

    std::cout << x << " is " << ((x % 2 == 0) ? "even." : "odd.") << std::endl;

    return 0;
}