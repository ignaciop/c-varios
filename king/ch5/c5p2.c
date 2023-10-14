#include <stdio.h>

int main(void) {
    int hour;
    int minute;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);

    if (hour < 0 || hour >= 24) {
       printf("Invalid 24-hour time\n\n");
    } else if (hour == 0) {
       printf("Equivalent 12-hour time: 12:%.2d AM\n\n", minute);
    } else if (hour < 12) {
       printf("Equivalent 12-hour time: %d:%.2d AM\n\n", hour, minute);
    } else if (hour == 12) {
        printf("Equivalent 12-hour time: %d:%.2d PM\n\n", hour, minute);
    } else { 
        printf("Equivalent 12-hour time: %d:%.2d PM\n\n", hour - 12, minute);
    }
    
    return 0;
}