/* process.c
 * implements a binary tree, uses it for making a process tree
 * Ignacio Poggi, 20240903
 */
 
#include "process.h"

struct process* make_process(int pid, int mem_used) {
    assert(pid >= 0);
    assert(mem_used > 0);
    
    struct process *new_proc = (struct process *)malloc(sizeof(struct process));
    
    if (new_proc == NULL) {
        perror("Cannot allocate memory for new process");
        
        exit(EXIT_FAILURE);
    }
    
    new_proc->pid = pid;
    new_proc->mem_used = mem_used;
    new_proc->left = new_proc->right = NULL;
    
    return new_proc;
}

void helper_print_postorder(struct process *root) {
	/* Recursively prints a binary tree using postorder traversal */
	/* PRE: none */
	/* POST: none */
	if (root != NULL) {
		helper_print_postorder(root->left);
		helper_print_postorder(root->right);
		print_process(root);
	}
}

void print_postorder(struct process *root) {
    printf("%s", "Postorder: ");
	
	helper_print_postorder(root);
	
	printf("\n");
}

void helper_print_inorder(struct process *root) {
	/* Recursively prints a binary tree using inorder traversal */
	/* PRE: none */
	/* POST: none */
	if (root != NULL) {
	    helper_print_inorder(root->left);
		print_process(root);
		helper_print_inorder(root->right);
	}
}

void print_inorder(struct process *root) {
	/* Prints a binary tree using inorder traversal */
	/* PRE: none */
	/* POST: none */
	printf("%s", "Inorder: ");
	
	helper_print_inorder(root);
	
	printf("\n");
}

void printGivenLevel(struct process *root, int level) {
    if (root == NULL) {
        return;
    }
    
    if (level == 1) {
        printf("%d ", root->pid);
    } else {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

int height(struct process *root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void helper_print_levelorder(struct process *root, int currentLevel, int maxLevel) {
	/* Recursively prints a binary tree using levelorder traversal */
	/* PRE: none */
	/* POST: none */
	if (currentLevel > maxLevel) {
	    return;
	}
	
	printGivenLevel(root, currentLevel);
	
    helper_print_levelorder(root, currentLevel + 1, maxLevel);
}

void print_levelorder(struct process *root) {
    /* Prints a binary tree using levelorder traversal */
	/* PRE: none */
	/* POST: none */
	printf("%s", "Levelorder: ");
	
	int h = height(root);
	helper_print_levelorder(root, 1, h);
	
	printf("\n");
}

int num_nodes(struct process *root) {
    if (root == NULL) {
        return 0;
    } else {
        int ln = num_nodes(root->left);
        int rn = num_nodes(root->right);
        
        return ln + rn + 1;
    } 
}

int is_complete(struct process *root) {
    int complete = 0;
    
    if (root == NULL) {
        complete = 1;
        
        return complete;
    }
    
    int h1 = height(root->left);
    int h2 = height(root->right);
    
    if (h1 == h2 || h1 == h2 + 1) {
        complete = 1;
    }
    
    return (complete && is_complete(root->left) && is_complete(root->right));
}

void helper_remove_all(struct process *root) {
    if (root == NULL) {
        return;
    }
    
    helper_remove_all(root->left);
    helper_remove_all(root->right);
        
    free(root);
    root = NULL;
}

void remove_all(struct process **root) {
    /* Check first if address is valid */
    if (root == NULL) {
        return;
    }
    
    /* Proceed to recursively remove actual root node */
    helper_remove_all(*root);
    
    /* Leave pointer to root node as NULL */
    *root = NULL;
}

int contains_pid(struct process *root, int value) {
    int cp = 0;
    
    if (root != NULL) {
        if (root->pid == value) {
            cp = 1;
        } else {
            cp = contains_pid(root->left, value) || contains_pid(root->right, value);
        }
    }
    
    return cp;
}

int total_mem(struct process *root) {
    int sum_tm = 0;
    
    if (root != NULL) {
        sum_tm += root->mem_used + total_mem(root->left) + total_mem(root->right);
    }
    
    return sum_tm;
}

int can_add(struct process *root, struct process *new_node, int max_mem) {
    assert(new_node != NULL);
    
    int cp = contains_pid(root, new_node->pid);
    int tm = total_mem(root) + new_node->mem_used;
    
    return (!cp && (tm <= max_mem));
}


/* Function to insert a node in level-order */
void insert_levelorder(struct process** root, struct process* to_add, int max_mem) {
    assert(can_add(*root, to_add, max_mem));

    if (*root == NULL) {
        *root = to_add;
        return;
    }
    
    struct queue *q = NULL;
    enqueue(*root, &q);
    
    while(peek(&q) != NULL) {
        struct process *temp = peek(&q)->proc;
        dequeue(&q);
        
        if (temp->left == NULL) {
            temp->left = to_add;
            return;
        } else if (temp->right == NULL) {
            temp->right = to_add;
            return;
        } else {
            enqueue(temp->left, &q);
            enqueue(temp->right, &q);
            
            //struct process *n = (dequeue(&q));
            //insert_levelorder(&n, to_add, max_mem);  
        }
    }
    
    assert(is_complete(*root));
}


struct process *create_tree(int first_pid, int max_mem, int mem_per_proc, int num_nodes) {
    struct process *root = make_process(first_pid, mem_per_proc);
    
    for (int i = 1; i < num_nodes; i++) {
        struct process *child = make_process(first_pid + i, mem_per_proc);
        
        insert_levelorder(&root, child, max_mem);
    }
    
    return root;
}

// Helper function to check if the tree is sorted in level-order
int is_sorted_recursive(struct process *node, int *last_pid) {
    if (node == NULL) {
        return 1; // An empty subtree is considered sorted
    }

    // Check if current node's PID is greater than the last seen PID
    if (node->pid <= *last_pid) {
        return 0; // Tree is not sorted
    }
    
    // Update the last seen PID
    *last_pid = node->pid;

    // Recursively check left and right children
    return is_sorted_recursive(node->left, last_pid) && is_sorted_recursive(node->right, last_pid);
}

// Wrapper function for is_sorted
int is_sorted(struct process *root) {
    if (root == NULL) {
        return 1; // An empty subtree is considered sorted
    }
    
    int last_pid = -1; // Initialize to a value less than any possible PID
    
    struct process *child = root->left;
    
    return is_sorted_recursive(root, &last_pid);
}


struct process *get_min(struct process *root, int smallest_val) {return NULL;}
int rebuild_tree(struct process **root) {return 0;}
int kill(struct process **root, int pid) {return 0;}