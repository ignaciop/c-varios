/*  
 *  run_length_encoding.c
 *  Ignacio Poggi; 20240901
 */

#include <stdio.h>
#include <stdlib.h>

#define N 50

void encode(char* string);

int main(void) {
    char buffer[N];
    int limit = 0;
    
    printf("%s\n", "Enter a string of at most 50 characters");
    
    char c = ' ';
    
    while ((c = getchar()) != '\n') {
        if (limit > N - 1) {
            break;
        }
        
        buffer[limit] = c;
        limit++;
    }
    
    buffer[limit] = '\0';
    
    encode(buffer);
    
    return EXIT_SUCCESS;
}

void encode(char* string) {
    /* Upper limit of actual string */
    int limit = 0;
    
    while (*(string + limit) != '\0') {
        limit++;
    }
    
    char characters[N]; /* Char array to store each char */
    int char_freqs[N]; /* Int array to store frequency of each char in string*/
    int tmp_count = 1; /* Temp storage of each char freq */
    int i = 0;
    int index = 0; /* Valid index for characters and char_freqs arrays */
    
    while (i < limit) {
        if (*(string + i) == *(string + i + 1)) {
            ++tmp_count;
        } else {
            *(char_freqs + index) = tmp_count;
            *(characters + index) = *(string + i);
            index++;
            tmp_count = 1;
        }
        
        i++;
    }
    
    for (int i = 0; i < limit; i++) {
        printf("%c", *(string + i));
    }
    
    printf("%s", " -> ");
    
    for (int j = 0; j < index; j++) {
        printf("%d%c", *(char_freqs + j), *(characters + j));
    }
    
    printf("\n");
}