#include <iostream>

int main() {
    int terms = 1;
    unsigned long long int s1 = 4;
    unsigned long long int s2 = 1;
    unsigned long long int term1 = s1;
    unsigned long long int term2 = s2;

    do {
        term1 += 6;
        s1 += term1;

        term2 += 7;
        s2 += term2;

        terms++;
    } while (s2 <= s1 * 100);

    std::cout << "With " << terms << " terms, S2 becames at least 100 greater than S1." << std::endl;

    return 0;
}