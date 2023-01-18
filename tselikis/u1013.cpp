#include <iostream>
#include <cstring>

int main() {
    const int ARRAY_SIZE = 101;
    char str1[ARRAY_SIZE];
    char str2[ARRAY_SIZE];

    std::cout << "Enter first string: ";
    std::cin.getline(str1, sizeof(str1));

    std::cout << "Enter second string: ";
    std::cin.getline(str2, sizeof(str2));
    
    for (int i = 0; i < strlen(str1) ; i++) {
    }

    return 0;
}