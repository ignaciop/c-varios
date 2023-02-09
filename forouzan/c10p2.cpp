#include <iostream>
#include <string>
#include <cctype>

void strToUpper(std::string& str);

int main() {
    std::string s {};

    std::cout << "Enter a string: ";
    getline(std::cin, s);

    strToUpper(s);

    std::cout << s << std::endl; 

    return 0;
}

void strToUpper(std::string& str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
}