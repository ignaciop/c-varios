#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_tag {IDENTIFIER, QUALIFIER, TYPE};

struct token {
    char type;
    char string[MAXTOKENLEN];
};

enum type_tag classify_string(void);
void gettoken(void);
void read_to_first_identifier(void);
void deal_with_arrays(void);
void deal_with_function_args(void);
void deal_with_pointers(void);
void deal_with_declarator(void);

#endif