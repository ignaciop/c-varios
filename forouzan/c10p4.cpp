#include <iostream>
#include <string>

int countChar(const std::string& str, char ch);
void removeOneChar(std::string& str, char ch);
void removeDuplicates(std::string& str);

int main() {
    std::string s {};
    
    std::cout << "Enter a string: ";
    getline(std::cin, s);

    removeDuplicates(s);

    std::cout << s << std::endl; 

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

void removeOneChar(std::string& str, char ch) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ch) {
            str.erase(i, 1);
            break;
        }
    }
}

void removeDuplicates(std::string& str) {
    for (int i = 0; i < str.length(); i++) {
        int cc = countChar(str, str[i]);

        if (cc > 1) {
            removeOneChar(str, str[i]);
            cc--;
        }
    }
}