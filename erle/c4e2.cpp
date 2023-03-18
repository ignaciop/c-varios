#include <iostream>
#include <string>

void hello(const std::string_view& s);

int main() {
    std::cout << "Enter your name: ";
    std::string name {};
    getline(std::cin, name);

    hello(name);

    return 0;
}

void hello(const std::string_view& s) {
    std::cout << "Hello " << s << std::endl;
}