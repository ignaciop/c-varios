#include <stdio.h>

void string_copy(char dest[], const char source[]) {
    int i = 0;
    
    // Copy characters one by one until the null-terminator is encountered
    while (source[i] != '\0') {
        dest[i] = source[i];

        i++;
    }
    
    // Add the null-terminator to the destination string
    dest[i] = '\0';
}

int main() {
    char dest[100]; // Destination string buffer
    const char source1[] = "Hello, World!";
    const char source2[] = "Custom String Copy Function";
    
    // Copy source1 to dest
    string_copy(dest, source1);
    printf("After copying source1: %s\n", dest);
    
    // Copy source2 to dest
    string_copy(dest, source2);
    printf("After copying source2: %s\n", dest);
    
    return 0;
}