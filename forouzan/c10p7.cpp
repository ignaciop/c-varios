#include <iostream>
#include <string>

std::string insertInMiddle(std::string str1, std::string str2) {
    int length = str2.length();

    if (length % 2 == 1) {
        str2 += str2[length - 1];

        length++;
    }

    int mid = length / 2;

    return str2.substr(0, mid) + str1 + str2.substr(mid, length);
}

int main() {
    std::string str1, str2;
    
    std::cout << "Enter the first string: ";
    getline(std::cin, str1);
    
    std::cout << "Enter the second string: ";
    getline(std::cin, str2);
    
    std::cout << "Result: " << insertInMiddle(str1, str2) << std::endl;

    return 0;
}