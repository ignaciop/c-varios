#include <stdio.h>

int main(void) {
    float f1 = 45.3f;

    printf("%-8.1e\n", f1);
    printf("%10.6e\n", f1);
    printf("%-8.3f\n", f1);
    printf("%6.0f\n", f1);

    return 0;
}