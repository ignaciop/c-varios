#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    printf("%s\t\t\t%s\t\t%s\t\t%s\n", "Type", "Sizeof", "Max Value", "Min value");
    printf("%s\t\t\t%zu\t\t%d\t\t\t%d\n", "char", sizeof(char), SCHAR_MAX, SCHAR_MIN);
    printf("%s\t\t%zu\t\t%d\t\t\t%d\n", "unsigned char", sizeof(unsigned char), UCHAR_MAX, 0);
    printf("%s\t\t\t%zu\t\t%d\t\t\t%d\n", "short", sizeof(short), SHRT_MAX, SHRT_MIN);
    printf("%s\t\t\t%zu\t\t%d\t\t%d\n", "int", sizeof(int), INT_MAX, INT_MIN);
    printf("%s\t\t%zu\t\t%ld\t\t%d\n", "unsigned int", sizeof(unsigned int), UINT_MAX, 0);
    printf("%s\t\t%zu\t\t%lu\t%d\n", "unsigned long", sizeof(unsigned long), ULONG_MAX, 0);
    printf("%s\t\t\t%zu\t\t%2.2e\t\t%2.2e\n", "float", sizeof(float), FLT_MAX, FLT_MIN);

    return 0;
}