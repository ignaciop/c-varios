#include <iostream>
#include <cstring>

int main() {
    const int ARRAY_SIZE = 101;
    char str1[ARRAY_SIZE];
    char str2[ARRAY_SIZE];

    std::cout << "Enter first string: ";
    std::cin.getline(str1, sizeof(str1));

    std::cout << "Enter second string: ";
    std::cin.getline(str2, sizeof(str2));

    char *p, *q, *r;

    if (str2 && (q = r = strstr(str1, str2)) != NULL) {
        int len = strlen(str2);

        while ((r = strstr(p = r + len, str2)) != NULL) {
            while (p < r) {
                *q++ = *p++;
            }
        }

        while ((*q++ = *p++) != '\0') {
            continue;
        }
    }

    std::cout << str1 << std::endl;

    return 0;
}