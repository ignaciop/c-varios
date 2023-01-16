//TODO: fix me

#include <iostream>
#include <cstring>

int main() {
    char str1[101];
    char str2[101];
    int string_appears = 0;
    int partial_string_appears = 0;

    std::cout << "Enter first string: ";
    std::cin.getline(str1, sizeof(str1));

    do {
        std::cout << "Enter second string (shorter than first): ";
        std::cin.getline(str2, sizeof(str2));
    } while (strlen(str2) > strlen(str1));

    char *p1 = str1;
    char *p2 = str2;

    while (p1 <= str1 + (strlen(str1) - 1)) {
        while (p2 <= str2 + (strlen(str2) - 1)) {
            if (*p1 == *p2) {
                partial_string_appears++;
            }

            p1++;
            p2++;

            if (partial_string_appears == strlen(str2)) {
                string_appears++;
                partial_string_appears = 0;
            }
        }

        //p1++;
        p2 = str2;
    }

    std::cout << str2 << " appears " << string_appears << " times in "
                << str1 << std::endl;

    std::cout << '\n';
        
    return 0;
}