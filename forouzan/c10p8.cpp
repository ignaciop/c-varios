#include <iostream>
#include <string>
#include <cctype>

bool isPalindrome(std::string& str);

int main() {
    std::string strg;

    std::cout << "Enter a string: ";
    getline (std::cin, strg);

    if (isPalindrome(strg)) {
        std::cout << strg << " is a palindrome.";
    } else {
        std::cout << strg << " is not a palindrome.";
    }

    return 0;
}

/*
The is_palindrome function takes a string as input and returns a boolean value 
indicating whether the string is a palindrome or not. The function first 
initializes two variables i and j to 0 and the length of the string minus 1,
respectively. These variables will be used to traverse the string from both 
ends.

The function then uses a while loop to iterate over the string until i and j
meet in the middle. The loop contains two nested while loops, which skip over
any non-alphanumeric characters. The characters are then compared using the
tolower function, which converts both characters to lowercase before 
comparing them. If the characters are not equal, the function returns false,
indicating that the string is not a palindrome. If the loop completes 
without returning false, the function returns true, indicating that the 
string is a palindrome.
*/

bool isPalindrome(std::string& str) {
    int i = 0, j = str.length() - 1;

    while (i < j) {
        while (!isalnum(str[i]) && i < j) i++;

        while (!isalnum(str[j]) && i < j) j--;

        if (tolower(str[i]) != tolower(str[j]))
            return false;

        i++, j--;
    }

    return true;
}