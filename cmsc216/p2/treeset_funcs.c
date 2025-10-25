#include "treeset.h"

void treeset_init(treeset_t *tree) {
    if (tree != NULL) {
        tree->root = NULL;
        tree->size = 0;
    }
}

int treeset_insert(treeset_t *tree, char name[]) {
    int inserted = 0;
    
    if (tree != NULL) {
        tsnode_t *new_node = (tsnode_t *)malloc(sizeof(tsnode_t));
        
        if (new_node == NULL) {
            perror("Cannot allocate memory for new node\n");
            
            exit(EXIT_FAILURE);
        }
        
        strncpy(new_node->name, name, sizeof(new_node->name) - 1);
        new_node->name[sizeof(new_node->name) - 1] = '\0'; // ensure null termination
        
        new_node->left = NULL;
        new_node->right = NULL;
        
        if (tree->root == NULL) {
            tree->root = new_node;
            
            inserted = 1;
            
            goto exit_tag;
        }
        
        tsnode_t *current = tree->root;
        tsnode_t *parent = NULL;

        while (current != NULL) {
            int cmp = strcmp(name, current->name);

            if (cmp == 0) {
                // Duplicate found — don't insert
                free(new_node);
                
                inserted = 0;
                
                goto exit_tag;
            }

            parent = current;
            
            if (cmp < 0) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        // Insert new node as child of parent
        if (strcmp(name, parent->name) < 0) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
        
        inserted = 1;
    }
    
    exit_tag:
    
    tree->size = (inserted == 0) ? tree->size : tree->size + 1;
    
    return inserted;
}

int treeset_find(treeset_t *tree, char name[]) {
    int found = 0;
    
    if (tree != NULL) {
        tsnode_t *cur = tree->root;
        
        while (cur != NULL) {
            int cmp_res = strcmp(name, cur->name);
            
            if (cmp_res == 0) {
                found = 1;
                
                break;
            } else if (cmp_res < 0) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
    }
    
    return found;
}

void treeset_clear(treeset_t *tree) {
    if (tree != NULL) {
        tsnode_remove_all(tree->root);
    }
    
    tree->root = NULL;
    tree->size = 0;
}

void treeset_print_revorder(treeset_t *tree) {
    if (tree != NULL && tree->root != NULL) {
        tsnode_print_revorder(tree->root, 0);
    }
}

void treeset_print_preorder(treeset_t *tree) {
    if (tree != NULL) {
        tsnode_write_preorder(tree->root, stdout, 0);
    }
}

void treeset_save(treeset_t *tree, char *fname) {
    if (tree != NULL && fname != NULL) {
        FILE *fp = fopen(fname, "w");
        
        if (fp == NULL) {
            perror("Cannot open file for writing.\n");
            
            exit(EXIT_FAILURE);
        }
        
        tsnode_write_preorder(tree->root, fp, 0);
        
        fclose(fp);
    }
}

int treeset_load(treeset_t *tree, char *fname) {
    int loaded = 0;
    
    treeset_clear(tree);
    
    if (tree != NULL && fname != NULL) {
        FILE *fp = fopen(fname, "r");
        
        if (fp == NULL) {
            printf("%s\n", "Cannot open file for reading.");
            
            goto exit_tag;
        }
        
        char temp_name[128];
        
        while (fscanf(fp, "%127s\n", temp_name) == 1) {
            treeset_insert(tree, temp_name);
        }
        
        fclose(fp);
        
        loaded = 1;
    }
    
    exit_tag:
    
    return loaded;
}

void tsnode_remove_all(tsnode_t *cur) {
    if (cur != NULL) {
        tsnode_remove_all(cur->left);
        tsnode_remove_all(cur->right);
        
        free(cur);
        cur = NULL;
    }
}

void tsnode_print_revorder(tsnode_t *cur, int indent) {
    if (cur != NULL) {
        tsnode_print_revorder(cur->right, indent + 1);

        // 2. Print current node (with indentation)
        for (int i = 0; i < indent; i++) {
            printf("  "); // two spaces per indent level
        }
        
        printf("%s\n", cur->name);

        // 3. Traverse left subtree
        tsnode_print_revorder(cur->left, indent + 1);
    }
}

void tsnode_write_preorder(tsnode_t *cur, FILE *out, int depth) {
    if (cur != NULL && out != NULL) {
        for (int i = 0; i < depth; ++i) {
            fprintf(out, "%s", "  ");
        }
        
        fprintf(out, "%.127s\n", cur->name);
        
        tsnode_write_preorder(cur->left, out, depth + 1);
        tsnode_write_preorder(cur->right, out, depth + 1);
    }
}
