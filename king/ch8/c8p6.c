#include <stdio.h>
#include <ctype.h>

#define BUFFER_MAX_SIZE 256

int main(void) {
    char buffer[BUFFER_MAX_SIZE] = {0};
    char ch = ' ';

    printf("Enter message: ");

    int actual_size = 0;

    while ((ch = getchar()) != '\n' && actual_size < BUFFER_MAX_SIZE) {
        buffer[actual_size] = toupper(ch);
        actual_size++;
    }

    for (int i = 0; i < actual_size; i++) {
        switch (buffer[i]) {
            case 'A':
                buffer[i] = '4';
                break;
            case 'B':
                buffer[i] = '8';
                break;
            case 'E':
                buffer[i] = '3';
                break;
            case 'I':
                buffer[i] = '1';
                break;
            case 'O':
                buffer[i] = '0';
                break;
            case 'S':
                buffer[i] = '5';
                break;
            default:
                break;
        }
    }

    printf("In B1FF-speak: ");

    for (int i = 0; i < actual_size; i++) {
        printf("%c", buffer[i]);
    }

    printf("!!!!!!!!!!\n");

    return 0;
}