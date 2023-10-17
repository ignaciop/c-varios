#include <stdio.h>

int main() {
    double total = 0.0, words = 1.0;
    char c = ' ';

    printf("Enter a sentence: ");

    while ((c = getchar()) != '\n') {
        if (c != ' ') {
            total++;
        } else { 
            words++;
        }
    }

    printf("Average word length: %.1f\n", total / words);

    return 0;
}