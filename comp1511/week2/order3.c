#include <stdio.h>

int main(void) {
    int n1, n2, n3;

    printf("Enter integer: ");
    scanf("%d", &n1);

    printf("Enter integer: ");
    scanf("%d", &n2);

    printf("Enter integer: ");
    scanf("%d", &n3);
    
    if (n1 <= n2) {
        if (n2 <= n3) {
            printf("The integers in order are: %d %d %d\n", n1, n2, n3);
        } else {
            if (n1 <= n3) {
                printf("The integers in order are: %d %d %d\n", n1, n3, n2);
            } else {
                printf("The integers in order are: %d %d %d\n", n3, n1, n2);
            }
        }
    } else {
        if (n1 <= n3) {
            printf("The integers in order are: %d %d %d\n", n2, n1, n3);
        } else {
            if (n2 <= n3) {
                printf("The integers in order are: %d %d %d\n", n2, n3, n1);
            } else {
                printf("The integers in order are: %d %d %d\n", n3, n2, n1);
            }
        }
    }

    return 0;
}