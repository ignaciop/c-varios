#include <stdio.h>

void display_line(void); /* function prototype*/

/* function definition */
int main(void) {
    display_line(); /* statement */

    printf("\n Teach Yourself C In One Hour a Day!\n"); /* statement */

    display_line(); /* statement */

    return 0; /* statement */
}

/* print asterisk line */ /* comment line */

/* function definition */
void display_line(void) {
    int counter; /* variable definition */ 

    /* for statement */
    for (counter = 0; counter < 30; counter++)
        printf("*"); /* statement */
}

/* end of program */ /* comment line */