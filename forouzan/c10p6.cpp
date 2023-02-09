#include <iostream>
#include <string>

std::string replace_substring(std::string s, std::string target, std::string replacement) {
    int pos = s.find(target);

    if (pos == std::string::npos) {
        return s;
    }

    return s.replace(pos, target.length(), replacement);
}

int main() {
    std::string s = "Hello, world!";
    std::string target = "world";
    std::string replacement = "universe";

    std::cout << "Original string: " << s << std::endl;
    std::cout << "Replaced string: " << replace_substring(s, target, replacement) << std::endl;
    
    return 0;
}