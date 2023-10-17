#include <stdio.h>

int main(void) {
    int hour = 0, minute = 0;
    char ap = ' ';

    printf("Enter a 12-hour time: ");
    scanf("%d:%d %c", &hour, &minute, &ap);
    
    if (ap == 'P' || ap == 'p') {
        hour += 12;
    }

    printf("Equivalent 24-hour time: %d:%d\n", hour, minute);

    return 0;
}