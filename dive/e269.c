#include <string.h>
#include <ctype.h>
#include <stdio.h>

void uppercaseify(char *string){
    unsigned int i = 0, len = 0;

    if (string == NULL) {
        return; //error handling
    }

    len = strlen(string);

    while (i < len) {
        string[i] = toupper(string[i]);

        i++;
    }
}

int main(void){
    char string[30];

    strcpy(string, "yo ho ho");
    uppercaseify(string);

    printf("%s\n", string); //should print YO HO HO

    return 0;
}