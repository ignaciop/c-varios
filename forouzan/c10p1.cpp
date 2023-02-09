#include <iostream>
#include <string>

int countChar(const std::string& str, char ch);

int main() {
    std::string s {};
    char c {};

    std::cout << "Enter a string: ";
    getline(std::cin, s);

    std::cout << "Enter a char to look: ";
    c = getchar();

    int count = countChar(s, c);

    std::cout << "Number of times '" << c << "' appears in \"" << s << "\": "
                << count << std::endl; 

    return 0;
}

int countChar(const std::string& str, char ch) {
    int count = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ch) {
            count++;
        }
    }

    return count;
}