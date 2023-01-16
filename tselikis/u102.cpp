#include <iostream>
#include <string>

int main() {
    std::cout << "Enter a string: ";
    std::string s;
    getline(std::cin, s);

    int length = s.length();

    if (s[length - 1] == 'a' && s[length - 2] == 'a') {
        for (int i = 0; i < length; i++) {
            std::cout << s[length - 1 - i];
        }
    }

    std::cout << '\n';

    return 0;
}