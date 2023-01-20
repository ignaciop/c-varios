#include <iostream>
#include <string>

void capitalization(std::string str, int *p_low, int *p_up, int *p_dig);

int main() {
    int low = 0;
    int up = 0;
    int dig = 0;

    int *p_low = &low;
    int *p_up = &up;
    int *p_dig = &dig;

    std::cout << "Enter a string: ";
    std::string s;
    getline(std::cin, s);

    if (s[0] == 'a' && s[s.length() - 1] == 'q') {
        capitalization(s, p_low, p_up, p_dig);

        std::cout << "Lowercase letters: " << *p_low << std::endl;
        std::cout << "Uppercase letters: " << *p_up << std::endl;
        std::cout << "Digits: " << *p_dig << std::endl;
    } else {
        std::cout << "The string must begin with 'a' and end with 'q'" << std::endl;
    }

    return 0;
}

void capitalization(std::string str, int *p_low, int *p_up, int *p_dig) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            (*p_low)++;
        }

        if (str[i] >= 'A' && str[i] <= 'Z') {
            (*p_up)++;
        }

        if (str[i] >= '0' && str[i] <= '9') {
            (*p_dig)++;
        }
    }
}