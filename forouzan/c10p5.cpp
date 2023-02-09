#include <iostream>
#include <string>

std::string commonCharacters(std::string str1, std::string str2);

int main() {
    std::string s {};
    std::string t {};

    std::cout << "Enter a string: ";
    getline(std::cin, s);

    std::cout << "Enter another string: ";
    getline(std::cin, t);

    std::string cm = commonCharacters(s, t);

    std::cout << cm << std::endl;

    return 0;
}

std::string commonCharacters(std::string str1, std::string str2) {
    // remove duplicates from each string
    std::string newStr1 = "", newStr2 = "";
    for (int i = 0; i < str1.length(); i++) {
        if (newStr1.find(str1[i]) == std::string::npos) {
            newStr1 += str1[i];
        }
    }

    for (int i = 0; i < str2.length(); i++) {
        if (newStr2.find(str2[i]) == std::string::npos) {
            newStr2 += str2[i];
        }
    }

    // create the string with common characters
    std::string commonStr = "";
    
    for (int i = 0; i < newStr1.length(); i++) {
        if (newStr2.find(newStr1[i]) != std::string::npos) {
            commonStr += newStr1[i];
        }
    }

    return commonStr;
}