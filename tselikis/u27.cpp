#include <iostream>

int main() {
    int i = 123;
    int c = (i / 100);
    int d = (i % 100) / 10;
    int u = (i % 100) - (10 * d);

    std::cout << "Sum of digits of " << i << ": " << c + d + u << std::endl;

    return 0;
}