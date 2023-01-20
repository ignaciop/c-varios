#include <iostream>

int strlen(char *p_str);

int main() {
    char cstr[255] = {};

    std::cout << "Enter a string: ";
    std::cin.getline(cstr, sizeof(cstr));

    int length = strlen(cstr);

    std::cout << "String length: " << length << std::endl;

    return 0;
}

int strlen(char *p_str) {
    int length = 0;

    while (*p_str != '\0') {
        length++;
        p_str++;
    }

    return length;
}
