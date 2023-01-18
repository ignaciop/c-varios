#include <iostream>
#include <string>

int main() {
    std::string str;
    char ch;
    char prev;

    std::cout << "Enter character: ";

    while ((ch = std::cin.get()) != 'q' && ch != EOF && str.length() <= 100) {
        if (str.length() == 0) {
            prev = ch;
            str += ch;
        } else {
            if (ch != prev) {
                str += ch;
                prev = ch;
            } else {
                continue;
            }
        }
    }

    std::cout << str << std::endl;
    
    return 0;
}