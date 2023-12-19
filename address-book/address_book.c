#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "address_book.h"

void print_person(const Person* person) {
    printf("Name: %s\nAge: %s\nPhone number: %s\n", person->name, person->age, 
            person->phone);
}

void print_address_book(const Address_book* address_book) {
    printf("==== Address book (%ld entries) ====\n\n", address_book->entries);
    
    for (size_t i = 0; i < address_book->entries; i++) {
        print_person(address_book->persons + i);
    }
}

Address_book* create_address_book(void) {
    Address_book *ab = (Address_book *)malloc(sizeof(Address_book));
    
    if (ab == NULL) {
        fprintf(stderr, "Cannot allocate memory for Address_book");
        
        exit(EXIT_FAILURE);
    }
    
    printf("%s", "Number of persons in the address book: ");
    scanf(" %zu", &(ab->entries));
    
    printf("%s\n", " ");
    getchar();
    
    ab->persons = (Person *)malloc(sizeof(Person) * ab->entries);
    
    if (ab->persons == NULL) {
        fprintf(stderr, "Cannot allocate memory for Person array");
        
        exit(EXIT_FAILURE);
    }
    
    for (size_t i = 0; i < ab->entries; i++) {
        printf("%s", "Name: ");
        fgets((ab->persons + i)->name, sizeof(char) * 80, stdin);
       
        printf("%s", "Age: ");
        fgets((ab->persons + i)->age, sizeof(char) * 4, stdin);
        
        printf("%s", "Phone number: ");
        fgets((ab->persons + i)->phone, sizeof(char) * 80, stdin);
        
        printf("%s\n", " ");
    }
    
    return ab;
}

void destroy_address_book(Address_book* address_book) {
    free(address_book->persons);
    address_book->persons = NULL;
    
    free(address_book);
    address_book = NULL;
}