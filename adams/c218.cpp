#include <iostream>

int strlen(const char *p_str);

int main() {
    char cstr[255] = {};

    std::cout << "Enter a string: ";
    std::cin.getline(cstr, sizeof(cstr));

    char* const p = &cstr[0];

    int length = strlen(p);

    std::cout << "String length: " << length << std::endl;

    return 0;
}

int strlen(const char *p_str) {
    int length = 0;

    while (*p_str != '\0') {
        length++;
        p_str++;
    }

    return length;
}
