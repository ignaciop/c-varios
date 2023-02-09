#include <iostream>
#include <string>

void removeChar(std::string& str, char ch);

int main() {
    std::string s {};
    char c {};

    std::cout << "Enter a string: ";
    getline(std::cin, s);

    std::cout << "Enter a char to erase: ";
    c = getchar();

    removeChar(s, c);

    std::cout << s << std::endl; 

    return 0;
}

void removeChar(std::string& str, char ch) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ch) {
            str.erase(i, 1);
        }
    }
}