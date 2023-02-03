#include <iostream>
#include <string>

int main() {
    std::cout << "Enter an integer number: ";
    int number = 0;
    std::cin >> number;

    std::string s = std::to_string(number);

    std::cout << s[1] << std::endl;  

    return 0;
}