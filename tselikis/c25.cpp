#include <iostream>

int main() {
    int i = 35;
    int d = i / 10;
    int u = i - (10 * d);

    std::cout << "Sum of digits of " << i << ": " << d + u << std::endl;

    return 0;
}