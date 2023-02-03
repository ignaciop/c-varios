#include <iostream>
#include <string>

int main() {
    std::cout << "Enter an integer number: ";
    int number = 0;
    std::cin >> number;

    if (number >= 100) {
        std::string s = std::to_string(number);

        std::cout << s[s.length() - 3] << s[s.length() - 2] << s[s.length() - 1] << std::endl;  
    }

    return 0;
}