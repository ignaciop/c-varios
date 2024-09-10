/*  
 *  numbers.c
 *  Ignacio Poggi; 20240902
 */

#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 1000

int evaluate_poly(int *coeffs, int x);
int get_first_digit(int x);
void values_poly(int* coeffs, int* values);
void first_values_poly(int* values);
void value_frequencies(int* values);

int main(void) {
    int coeffs[N] = {0};
    
    printf("%s\n", "Enter non-negative coefficients of Ax^4 + Bx^3 + Cx^2 + Dx + E");
    
    for (int i = 0; i < N; i++) {
        scanf(" %d", &coeffs[i]);
    }
    
    printf("%s", "p(x) = ");
    
    for (int i = 0; i < N; i++) {
        printf((i == N - 1) ? "%d\n" : "%dx^%d + ", coeffs[i], N - i - 1);
    }
    
    printf("\n%s", "Enter a value: ");
    int x = 0;
    scanf("%d", &x);
    
    int eval_poly = evaluate_poly(coeffs, x);
    
    printf("p(%d) = %d\n", x, eval_poly);
    
    printf("\n%d -> %d\n", 1, get_first_digit(1));
    printf("%d -> %d\n", 12, get_first_digit(12));
    printf("%d -> %d\n", 54712, get_first_digit(54712));
    
    int values[M] = {0};
    int fvalues[M] = {0};
    
    values_poly(coeffs, values);
    
    for (int i = 0; i < M; i++) {
        printf((i == M - 1) ? "%d\n" : "%d, ", values[i]);
    }
    
    first_values_poly(values);
    
     for (int i = 0; i < M; i++) {
        printf((i == M - 1) ? "%d\n" : "%d, ", values[i]);
    }
    
    for (int i = 0; i < N; i++) {
        printf((i == N - 1) ? "%d\n" : "%dx^%d + ", coeffs[i], N - i - 1);
    }
    
    value_frequencies(values);
     
    return EXIT_SUCCESS;
}

int evaluate_poly(int *coeffs, int x) {
    int res = 0;
    
    for (int i = 0; i < N; i++) {
        int j = 1;
        int pow = 1;
        
        while (j <= N - i - 1) {
            pow *= x;
            j++;
        }
        
        res += coeffs[i]*pow;
    }
    
    return res;
}

int get_first_digit(int x) {
    int digit = 0;
    
    while (x != 0) {
        digit = x % 10;
        x /= 10;
    }
    
    return digit;
}

void values_poly(int* coeffs, int* values) {
    for (int i = 0; i < M; i++) {
        values[i] = evaluate_poly(coeffs, i + 1); 
    }
}

void first_values_poly(int* values) {
    for (int i = 0; i < M; i++) {
        values[i] = get_first_digit(values[i]); 
    }
}

void value_frequencies(int* values) {
    int freqs[9] = {0};
    
    for (int i = 1; i <= 9; i++) {
        int count = 0;
        
        for (int j = 0; j < M; j++) {
            if (values[j] == i) {
                count++;
            }
        }
        
        freqs[i - 1] = count;
    }
    
    for (int i = 1; i <= 9; i++) {
        printf("%d: %.6lf%\n", i, ((double)freqs[i - 1]) / M * 100);
    }
}