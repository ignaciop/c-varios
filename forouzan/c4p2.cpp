#include <iostream>

int main() {
    std::cout << "Please enter three integers: ";
    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;

    if (a < b && b < c) {
        std::cout << a << std::endl;
    } else if (b < c) {
        std::cout << b << std::endl;
    } else {
        std::cout << c << std::endl;
    }

    return 0;
}