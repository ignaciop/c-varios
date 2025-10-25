#include "treeset.h"

int main(void) {
    /*
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
    */
    
    treeset_t nt;
    
    treeset_init(&nt);
    
    treeset_insert(&nt, "Lucas");
    treeset_insert(&nt, "Mike");
    treeset_insert(&nt, "Dustin");
    treeset_insert(&nt, "Will");
    treeset_insert(&nt, "El");
    
    printf("%d nodes\n", nt.size);
    
    treeset_print_revorder(&nt);
    treeset_print_preorder(&nt);
    
    int fm = treeset_find(&nt, "Mike");
    printf("%s FOUND\n", (fm == 1) ? "\b" : "NOT");
    
    fm = treeset_find(&nt, "Nancy");
    printf("%s FOUND\n", (fm == 1) ? "\b\b" : "NOT");
    
    treeset_insert(&nt, "Nancy");
    
    printf("%d nodes\n", nt.size);
    
    treeset_print_revorder(&nt);
    
    treeset_insert(&nt, "Mike");
    treeset_insert(&nt, "El");
    
    fm = treeset_find(&nt, "Max");
    printf("%s FOUND\n", (fm == 1) ? "\b\b" : "NOT");
    
    treeset_insert(&nt, "Max");
    
    treeset_print_revorder(&nt);
    
    fm = treeset_find(&nt, "Max");
    printf("%s FOUND\n", (fm == 1) ? "\b\b" : "NOT");
    
    fm = treeset_find(&nt, "Barb");
    printf("%s FOUND\n", (fm == 1) ? "\b\b" : "NOT");
    
    treeset_insert(&nt, "Barb");
    
    treeset_print_revorder(&nt);
    
    treeset_save(&nt, "data/stranger2.tree");
    
    printf("%s\n", "****************");
    
    treeset_load(&nt, "data/stranger.tree");
    
    treeset_print_revorder(&nt);
    
    treeset_clear(&nt);

    return EXIT_SUCCESS;
}