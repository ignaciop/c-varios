#include "parser.h"

int top = -1;

struct token stack[MAXTOKENS];
struct token this;

#define pop stack[top--]
#define push(s) stack[++top]=s

enum type_tag classify_string(void) {
    /* figure out the identifier type */
    char *s = this.string;

    if (!strcmp(s, "const")) {
        strcpy(s, "read-only");

        return QUALIFIER;
    }

    if (!strcmp(s, "volatile")) {
        return QUALIFIER;
    }

    if (!strcmp(s, "void")) {
        return TYPE;
    }

    if (!strcmp(s, "char")) {
        return TYPE;
    }

    if (!strcmp(s, "signed")) {
        return TYPE;
    }

   if (!strcmp(s, "unsigned")) {
        return TYPE;
    }

    if (!strcmp(s, "short")) {
        return TYPE;
    }

    if (!strcmp(s, "int")) {
        return TYPE;
    }

    if (!strcmp(s, "long")) {
        return TYPE;
    }

    if (!strcmp(s, "float")) {
        return TYPE;
    }

    if (!strcmp(s, "double")) {
        return TYPE;
    }

    if (!strcmp(s, "struct")) {
        return TYPE;
    }

    if (!strcmp(s, "union")) {
        return TYPE;
    }

    if (!strcmp(s, "enum")) {
        return TYPE;
    }

    return IDENTIFIER;
}

void gettoken(void) {
    /* read next token into "this "*/
    char *p = this.string;

    /* read past any spaces */
    while ((*p = getchar()) == ' ')
        ;
    
    if (isalnum(*p)) {
        /* it starts with A-Z, 0-9 read in identifier */
        while (isalnum(*++p = getchar()))
            ;
        
        ungetc(*p, stdin);
        *p = '\0';

        this.type = classify_string();
        
        return;
    }

    if (*p == '*') {
        strcpy(this.string, "pointer to");

        this.type = '*';

        return;
    }

    this.string[1] = '\0';
    this.type = *p;

    return;
}

void read_to_first_identifier(void) {
    gettoken();

    while (this.type != IDENTIFIER) {
        push(this);
        gettoken();
    }

    printf("%s is ", this.string);

    gettoken();
}

void deal_with_arrays(void) {
    while (this.type == '[') {
        printf("%s ", "array");

        gettoken(); /* a number or ']' */

        if (isdigit(this.string[0])) {
            printf("0..%d ", atoi(this.string) - 1);

            gettoken(); /* read the ']' */
        }

        gettoken(); /* read next past the ']' */

        printf("%s ", "of");
    }
}

void deal_with_function_args(void) {
    while (this.type != ')') {
        gettoken();
    }

    gettoken();

    printf("%s ", "function returning");
}

void deal_with_pointers(void) {
    while (stack[top].type == '*') {
        printf("%s ", pop.string);
    }
}

void deal_with_declarator(void) {
    /* deal with possible array/function following identifier */
    switch (this.type) {
    case '[':
        deal_with_arrays();
        break;
    case '(':
        deal_with_function_args();
        break;
    }

    deal_with_pointers();

    /* process tokens that we stacked while reading identifier */
    while (top >= 0) {
        if (stack[top].type == '(') {
            pop;
            gettoken(); /* read past ')' */
            deal_with_declarator();
        } else {
            printf("%s ", pop.string);
        }
    }
}