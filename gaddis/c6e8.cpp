#include <iostream>
#include <string>
#include <cctype>

std::string upperCaseIt(std::string s);
bool sameString(std::string s1, std::string s2);

int main() {
    std::string s1 = "";
    std::cout << "Enter first string: ";
    getline(std::cin, s1);

    std::string s2 = "";
    std::cout << "Enter second string: ";
    getline(std::cin, s2);

    std::cout << (sameString(s1, s2) ? "The strings are the same" : "The strings are different") << std::endl;

    return 0;
}

std::string upperCaseIt(std::string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }

    return s;
}

bool sameString(std::string s1, std::string s2) {
    return (upperCaseIt(s1) == upperCaseIt(s2));
}