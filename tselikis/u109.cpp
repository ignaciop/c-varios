#include <iostream>
#include <string>
#include <vector>

int main() {
    int i, words;
    std::string str;
    i = words = 0;

    std::cout << "Enter text: ";
    getline(std::cin, str);

    if(str[0] != ' ' && str[0] != '\t' && str[0] != '\0') { 
        /* If the first character is other than the space character, 
        it means that a word begins, sothe value of words is incremented. */
        words++;
    }

    while(str[i] != '\0') {
        if(str[i] == ' ' || str[i] == '\t') {
        /* Since more than one space character may be included between
        words, we check if the next character, that is str[i+1],
        is also a space character. If it isn't, it means that a new word 
        begins, so the value of words is increased. */
            if(str[i+1] != ' ' && str[i+1] != '\t' && str[i+1] != '\0') {
                words++;
            }
        }
        
        i++;
    }

    std::cout << "\nThe text contains " << words << " words\n";

    std::vector<std::string> separate_strings;

    std::string temp;

    for (int i = 0; i <= str.length() + 1; i++) {
        
            
        if (str[i] != ' ' && i != str.length()) {
            temp += str[i];
        } else {
            separate_strings.push_back(temp);
            temp = "";
        }   
    }
        
    for (auto it = separate_strings.rbegin(); it != separate_strings.rend(); it++) {
        std::cout << *it << " ";
    }

    std::cout << "\b\n";

    return 0;
}