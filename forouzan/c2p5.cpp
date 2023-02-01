#include <iostream>

int main() {
    std::cout << "Enter four integers: " << std::endl;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    std::cin >> a >> b >> c >> d;

    int sum = a + b + c + d;

    std::cout << a << " + " << b << " + " << c << " + " << d << " = "
                << sum << std::endl;

    return 0;
}