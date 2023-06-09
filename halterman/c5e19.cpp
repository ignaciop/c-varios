#include <iostream>

int main() {
    std::cout << "Enter five integers: ";
    int a {}, b {}, c {}, d {}, e {};
    std::cin >> a >> b >> c >> d >> e;

    if ((a == b) || (a == c) || (a == d) || (a == e) || (b == c) || (b == d) || (b == e) || (c == d) || (c == e) || (d == e)) {
        std::cout << "DUPLICATES" << std::endl;
    } else {
        std::cout << "ALL UNIQUE" << std::endl;
    }

    return 0;
}