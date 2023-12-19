#include <stdlib.h>
#include "address_book.h"

int main(void) {
    Address_book *ab = create_address_book();
    
    print_address_book(ab);
    
    destroy_address_book(ab);
    
    return EXIT_SUCCESS;
}