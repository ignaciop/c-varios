#include <stdio.h>

int main(void) {
    char ch = ' ', first_name_initial = ' ';

    printf("Enter a first and last name: ");
    scanf(" %c", &first_name_initial);

    while ((ch = getchar()) != ' ')
        ;

    while ((ch = getchar()) == ' ')
       ;

    do {
        putchar(ch);
    } while ((ch = getchar()) != '\n' && ch != ' ');

    printf(", %c.\n", first_name_initial);
    
    return 0;
}