#include <stdio.h>

void a(int i) {
    if (i > 0) {
        a(--i);
    } else {
        printf("%s\n", "i has reached zero");
    }
}

int main(void) {
    a(1);

    return 0;
}