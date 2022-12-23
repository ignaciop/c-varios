#include <iostream>
#include <string>

int GetNumCharacters(std::string& strInput, char chToFind) {
    int nNumCharactersFound = 0;
    size_t nCharOffset = strInput.find(chToFind);

    while(nCharOffset != std::string::npos) {
        ++nNumCharactersFound;
        
        nCharOffset = strInput.find(chToFind, nCharOffset + 1);
    }

    return nNumCharactersFound;
}

int main() {
    std::cout << "Please enter a string:"  << std::endl << "> ";
    std::string strInput;
    getline(std::cin, strInput);

    int nNumVowels = GetNumCharacters(strInput, 'a');
    nNumVowels += GetNumCharacters(strInput, 'e');
    nNumVowels += GetNumCharacters(strInput, 'i');
    nNumVowels += GetNumCharacters(strInput, 'o');
    nNumVowels += GetNumCharacters(strInput, 'u');

    std::cout << "The number of vowels in that sentence is: " << nNumVowels;

    return 0;
}