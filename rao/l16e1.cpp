#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::cout << "Enter a word: ";
    std::string word;
    std::cin >> word;

    std::string drow(word);
    std::reverse(drow.begin(), drow.end());

    if (drow == word) {
        std::cout << word << " is a palindrome." << std::endl;
    } else {
        std::cout << word << " is not a palindrome." << std::endl;
    }

    return 0;
}