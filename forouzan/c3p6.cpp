#include <iostream>
#include <string>

int main() {
    std::cout << "Enter an three-digit integer number: ";
    int number = 0;
    std::cin >> number;

    std::string s = std::to_string(number);
    std::string r = "";

    r[0] = s[s.length() - 1];
    r[1] = s[s.length() - 2];
    r[2] = s[s.length() - 3];

    int rn = std::stoi(r);

    std::cout << rn << std::endl;  
    
    return 0;
}