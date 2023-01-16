#include <iostream>
#include <cstring>

int main() {
    char str[101];

    std::cout << "Enter a string: ";
    std::cin.getline(str, sizeof(str));

    // Pointer to last non-null character in str
    char *p = str + (strlen(str) - 1);

    while (p >= str) {
        std::cout << *p;
        p--;
    }

    std::cout << '\n';
        
    return 0;
}