#include <stdio.h>

int main(void) {
    int n;

    scanf("%d", &n);

    if (n > 0) {
        printf("You have entered a positive number.\n");
    } else if (n < 0) {
        printf("Don't be so negative!\n");
    } else {
        printf("You have entered zero.\n");
    }
    
    return 0;
}