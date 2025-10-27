#include "treeset.h"

#define MAX_CMD_LENGTH 10
#define MAX_FNAME_LENGTH 128

int main(int argc, char *argv[]) {
    printf("%s\n", "Treeset Main");
    printf("%s\n", "Commands:");
    printf("%s\n", "  print:          shows contents of the tree in reverse sorted order");
    printf("%s\n", "  size:           prints the number of nodes currently in the tree");
    printf("%s\n", "  clear:          eliminates all elements from the tree");
    printf("%s\n", "  quit:           exit the program");
    printf("%s\n", "  add <name>:     inserts the given string into the tree, duplicates ignored");
    printf("%s\n", "  find <name>:    prints FOUND if the name is in the tree, NOT FOUND otherwise");
    printf("%s\n", "  preorder:       prints contents of the tree in pre-order which is how it will be saved");
    printf("%s\n", "  save <file>:    writes the contents of the tree in pre-order to the given file");
    printf("%s\n", "  load <file>:    clears the current tree and loads the one in the given file");
    
    int echo_flag = 0;
    
    if (argc > 1 && strcmp("-echo", argv[1]) == 0) {
        echo_flag = 1;
    }
    
    char cmd_buffer[MAX_CMD_LENGTH];
    
    treeset_t nt;
    
    treeset_init(&nt);
    
    while (1) {
        printf("%s", "TS#> ");
        
        scanf("%9s", cmd_buffer);
        
        if (strcmp(cmd_buffer, "print") == 0) {
            if (echo_flag == 1) {
                printf("%s\n", "print");
            }
            
            treeset_print_revorder(&nt);
        } else if (strcmp(cmd_buffer, "size") == 0) {
            int sz = nt.size;
            
            if (echo_flag == 1) {
                printf("%s\n", "size");
            }
            
            printf("%d %s\n", sz, (sz == 1) ? "node": "nodes");
        } else if (strcmp(cmd_buffer, "clear") == 0) {
            if (echo_flag == 1) {
                printf("%s\n", "clear");
            }
            
            treeset_clear(&nt);
        } else if (strcmp(cmd_buffer, "add") == 0) {
            char fn_buffer[MAX_FNAME_LENGTH];
            
            scanf("%127s", fn_buffer);
            
            if (echo_flag == 1) {
                printf("%s %s\n", "add", fn_buffer);
            }
            
            treeset_insert(&nt, fn_buffer);
        } else if (strcmp(cmd_buffer, "find") == 0) {
            char fn_buffer[MAX_FNAME_LENGTH];
            
            scanf("%127s", fn_buffer);
            
            if (echo_flag == 1) {
                printf("%s %s\n", "find", fn_buffer);
            }
            
            treeset_find(&nt, fn_buffer);
        } else if (strcmp(cmd_buffer, "preorder") == 0) {
            treeset_print_preorder(&nt);
        } else if (strcmp(cmd_buffer, "save") == 0) {
            char fn_buffer[MAX_FNAME_LENGTH];
            
            scanf("%127s", fn_buffer);
            
            if (echo_flag == 1) {
                printf("%s %s\n", "save", fn_buffer);
            }
            
            treeset_save(&nt, fn_buffer);
        } else if (strcmp(cmd_buffer, "load") == 0) {
            char fn_buffer[MAX_FNAME_LENGTH];
            
            scanf("%127s", fn_buffer);
            
            if (echo_flag == 1) {
                printf("%s %s\n", "load", fn_buffer);
            }
            
            treeset_load(&nt, fn_buffer);
        } else if (strcmp(cmd_buffer, "quit") == 0) {
            if (echo_flag == 1) {
                printf("%s\n", "quit");
            }
            
            treeset_clear(&nt);
            
            break;
        } else {
            continue;
        }
    }
    
    return EXIT_SUCCESS;
}
