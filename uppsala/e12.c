#include <stdio.h>

int fibonacci(int term);

int main(void) {
    int n = 0;

    printf("Give n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("%d\n", fibonacci(i));
    }
    
    return 0;
}

int fibonacci(int term) {
    if (term == 1 || term == 2) {
        return 1;
    } else {
        return (fibonacci(term - 1) + fibonacci(term - 2));
    }
}