#include <iostream>
#include <cstring>

int main() {
    char str[101];
    int del_chars = 0;
    int start_char_pos = 0;

    std::cout << "Enter a string: ";
    std::cin.getline(str, sizeof(str));

    do {
        std::cout << "How many characters are going to be deleted: ";
        std::cin >> del_chars;
    } while (del_chars > strlen(str));

    do {
        std::cout << "Position of first character to be deleted: ";
        std::cin >> start_char_pos;
    } while (start_char_pos > strlen(str));

    // Pointer to char in start_char_pos
    char *p = str + (start_char_pos - 1);

    while (p <= str + (start_char_pos - 1) + (del_chars - 1)) {
        *p = '#';
        p++;
    }

    p = str;

    while (p <= str + (strlen(str) - 1)) {
        if (*p != '#') {
            std::cout << *p;
        }

        p++;
    }

    std::cout << '\n';
        
    return 0;
}