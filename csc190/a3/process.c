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


// Function to insert a node in level-order
void insert_levelorder(struct process** root, struct process* to_add, int max_mem) {
    assert(can_add(*root, to_add, max_mem));

    if (*root == NULL) {
        *root = to_add;
    }
    
    struct queue *q;
    enqueue(*root, &q);
 
    while (peek(&q)) {
        struct queue* temp = peek(&q);
        dequeue(&temp);
 
        if (temp->left != NULL)
            enqueue(temp->left, &q);
        else {
            temp->left = to_add;
        }
 
        if (temp->right != NULL)
            enqueue(temp->right, &q);
        else {
            temp->right = to_add;
        }
    }
}

struct process *create_tree(int first_pid, int max_mem, int mem_per_proc, int num_nodes) {return NULL;}
int is_sorted(struct process *root) {return 0;}
struct process *get_min(struct process *root, int smallest_val) {return NULL;}
int rebuild_tree(struct process **root) {return 0;}
int kill(struct process **root, int pid) {return 0;}