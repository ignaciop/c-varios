#ifndef __ADDRESS_BOOK_H__
#define __ADDRESS_BOOK_H__

struct Person {
    char name[80];
    char age[4];
    char phone[80];
};

typedef struct Person Person;

struct Address_book {
    Person *persons;
    size_t entries;
};

typedef struct Address_book Address_book; 

/* Function declarations. Do not modify! Implement those functions in address_book.c */
void print_person(const Person* person);
void print_address_book(const Address_book* address_book);

Address_book* create_address_book(void);
void destroy_address_book(Address_book* address_book);

#endif /* __ADDRESS_BOOK_H__ */