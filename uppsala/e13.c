#include <stdio.h>

int main(void) {
    int n = 0;
    int x = 1, y = 1;

    printf("Give n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("%d\n", x);

        int t = x;
        x = y;
        y = t + y;
    }
    
    return 0;
}