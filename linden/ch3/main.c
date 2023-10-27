#include "parser.h"

int main(void) {
    /* put tokens on stack until we reach identifier */
    read_to_first_identifier();
    deal_with_declarator();

    printf("%s", "\n");

    return 0;
}