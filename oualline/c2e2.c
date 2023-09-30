#include <stdio.h>

int main(void) {
    int n1 = 0;
    int n2 = 0;

    printf("Enter an integer number: \n");
    scanf("%d", &n1);

    printf("Enter another integer number: \n");
    scanf("%d", &n2);

    printf("%d + %d = %d\n", n1, n2, n1 + n2);

    return 0;
}