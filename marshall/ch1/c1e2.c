#include <stdio.h>
#include <math.h>

int main(void) {
    printf("%s", "\t Number \t\t Square of Number\n\n");

    for (int i = 0; i <= 360; ++i) {
        printf("\t %d \t\t\t %lf \n", i, sqrt((double)i));
    }

    return 0;
}