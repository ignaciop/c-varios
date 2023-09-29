#include <stdio.h>

int main(void) {
    char is_uppercase;
    char letter;

    printf("Uppercase: ");
    scanf("%c", &is_uppercase);

    int index;
    printf("Index: ");
    scanf("%d", &index);

    if (is_uppercase == 'y') {
        letter = 'A' + index;
    } else {
        letter = 'a' + index;
    }

    printf("The letter is %c\n", letter);

    return 0;
}