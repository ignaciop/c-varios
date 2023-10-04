#include <stdio.h>

int main(void) {
    char input = 'y';
    int number = 0;

    do {
        printf("Give a number: ");
        scanf("%d", &number);

        int i = 1;

        while (i <= number) {
            printf("%d\n", i);

            i++;
        }

        printf("Run again (y/n)? ");
        scanf(" %c", &input);
    } while (input != 'n');

    printf("Exiting...\n");

    return 0;
}