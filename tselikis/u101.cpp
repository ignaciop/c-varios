#include <iostream>
#include <cstring>

int main() {
    char str1[101];
    char str2[101];
    char str3[101];

    char temp[101];

    std::cout << "Enter first string: ";
    std::cin.getline(str1, sizeof(str1));

    std::cout << "Enter second string: ";
    std::cin.getline(str2, sizeof(str2));

    std::cout << "Enter third string: ";
    std::cin.getline(str3, sizeof(str3));

    strcpy(temp, str1); // Copy str1 to temp
    strcpy(str1, str3); // Copy str3 to str1
    strcpy(str3, str2); // Copy str2 to str3
    strcpy(str2, temp); // Copy temp (str1) to str2

    std::cout << "After rotating one place to the right... " << std::endl;
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str3 << std::endl;

    return 0;
}