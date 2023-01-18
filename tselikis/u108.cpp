#include <iostream>
#include <string>

int main() {
    std::cout << "Enter a string: ";
    std::string s;
    getline(std::cin, s);

    for (int i = 0; i < s.size(); i++) {
        int j = i + 1;

        while (j < s.size()) {
            if (s[i] == s[j]) {
                s.erase(j, 1);
            } else {
                ++j;
            }
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] < 'A' || s[i] > 'Z' && s[i] < 'a' || s[i] > 'z') {  
            s.erase(i, 1);
            
            i--;
        }
    }

    std::cout << s << std::endl;
    
    return 0;
}