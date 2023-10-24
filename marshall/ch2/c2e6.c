#include <stdio.h>

int main(void) {
    int n = 0;
    
    printf("%s", "Enter a positive integer greater than or equal to 3: ");
    scanf("%d", &n);
    
    printf("All possible permutations of three positive integers less than or equal to %d:\n", n);

    // Generate and print permutations
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (i != j && i != k && j != k) {
                    printf("%d %d %d\n", i, j, k);
                }
            }
        }
    }

    return 0;
}