#include <stdio.h>

int main(void) {
    printf("%s", "\t Number \t\t Square of Number\n\n");

    for (int i = 0; i <= 25; ++i) {
        printf("\t %d \t\t\t %d \n", i, i * i);
    }

    return 0;
}