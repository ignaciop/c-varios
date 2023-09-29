#include <stdio.h>

int main(void) {
    int a, b, c;

    printf("Enter integer: ");
    scanf("%d", &a);  

    printf("Enter integer: ");
    scanf("%d", &b);  

    printf("Enter integer: ");
    scanf("%d", &c);
 
    printf("The integers in order are: %d %d %d\n", ((b < a)*(b < c)*b + (a < b)*(a < c)*a + (c < a)*(c < b)*c), ((b < a)*(b > c)*b + (b > a)*(b < c)*b + (a < b)*(a > c)*a + (a > b)*(a < c)*a + (c < a)*(c > b)*c + (c > a)*(c < b)*c), ((b > a)*(b > c)*b + (a > b)*(a > c)*a + (c > a)*(c > b)*c));

    return 0;
}