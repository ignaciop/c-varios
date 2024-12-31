/* 
 * process.c
 * implements a binary tree, uses it for making a process tree
 * Ignacio Poggi, 20240903
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "process.h"

struct process *make_process(int pid, int mem_used) {
    assert(pid >= 0);
    assert(mem_used > 0);
    
    struct process *new_proc = (struct process *)malloc(sizeof(struct process));
    
    if (new_proc == NULL) {
        perror("Cannot allocate memory for new process");
        
        exit(EXIT_FAILURE);
    }
    
    new_proc->pid = pid;
    new_proc->mem_used = mem_used;
    new_proc->left = NULL;
    new_proc->right = NULL;
    
    return new_proc;
}

static void helper_print_postorder(struct process *root) {
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

static void helper_print_inorder(struct process *root) {
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

static void print_given_level(struct process *root, int level) {
    if (root == NULL) {
        return;
    }
    
    if (level == 1) {
        printf("%d ", root->pid);
    } else {
        print_given_level(root->left, level - 1);
        print_given_level(root->right, level - 1);
    }
}

static int height(struct process *root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    int h = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    
    return h;
}

static void helper_print_levelorder(struct process *root, int currentLevel, int maxLevel) {
	/* Recursively prints a binary tree using levelorder traversal */
	/* PRE: none */
	/* POST: none */
	if (currentLevel > maxLevel) {
	    return;
	}
	
	print_given_level(root, currentLevel);
	
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
    int nn = 0;
    
    if (root != NULL) {
        int ln = num_nodes(root->left);
        int rn = num_nodes(root->right);
        
        nn = ln + rn + 1;
    }
    
    return nn;
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

static void helper_remove_all(struct process *root) {
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
    
    int ca = !cp && (tm <= max_mem);
    
    return ca;
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
static int is_sorted_recursive(struct process *node, int *last_pid) {
    if (node == NULL) {
        return 1; // An empty subtree is considered sorted
    }

    // Check if current node's PID is greater than the last seen PID
    if (node->pid <= *last_pid) {
        return 0; // Tree is not sorted
    }
    
    // Update the last seen PID
    *last_pid = node->pid;
    
    int is = is_sorted_recursive(node->left, last_pid) && is_sorted_recursive(node->right, last_pid);

    // Recursively check left and right children
    return is;
}

// Wrapper function for is_sorted
int is_sorted(struct process *root) {
    if (root == NULL) {
        return 1; // An empty subtree is considered sorted
    }
    
    int last_pid = -1; // Initialize to a value less than any possible PID
    
    struct process *child = root->left;
    
    int is = is_sorted_recursive(root, &last_pid);
    
    return is;
}

struct process *get_min(struct process *root, int smallest_val) {
    //assert(is_sorted(root));
    
    struct process *proc_min = NULL;
    
    if (root != NULL) {
        /* If the current node's pid is greater than or equal to smallest_val, it's a valid candidate */
        if (root->pid >= smallest_val) {
            proc_min = root;
        }
        
        /* Check the left subtree, which might contain smaller valid processes */
        struct process *left_min = get_min(root->left, smallest_val);
        
        if (left_min != NULL && left_min->pid >= smallest_val) {
            /* If a valid process was found in the left subtree, update proc_min if it's smaller */
            if (proc_min == NULL || left_min->pid < proc_min->pid) {
                proc_min = left_min;
            }
        }

        /* Check the right subtree, which might also contain valid processes */
        struct process *right_min = get_min(root->right, smallest_val);
        
        if (right_min != NULL && right_min->pid >= smallest_val) {
            /* If a valid process was found in the right subtree, update proc_min if it's smaller */
            if (proc_min == NULL || right_min->pid < proc_min->pid) {
                proc_min = right_min;
            }
        }
    }

    return proc_min;
}

/* Helper function to collect all nodes in level order */
static void collect_nodes(struct process *root, struct process **nodes, int *index) {
    if (root == NULL) {
        return;
    }

    struct queue *front = NULL;
    enqueue(root, &front);

    while (front != NULL) {
        struct process *current = dequeue(&front);
        
        if (current != NULL) {
            nodes[*index] = current;
            (*index)++;
            
            enqueue(current->left, &front);
            enqueue(current->right, &front);
        }
    }
}

/* Helper function to rebuild the tree using sorted nodes */
static struct process* rebuild_from_sorted_nodes(struct process **nodes, int num_nodes) {
    if (num_nodes == 0) {
        return NULL;
    }

    struct process *root = nodes[0];
    struct queue *front = NULL;
    enqueue(root, &front);
    int index = 1;

    while (index < num_nodes) {
        struct process *current = dequeue(&front);

        if (index < num_nodes) {
            current->left = nodes[index++];
            enqueue(current->left, &front);
        }
        
        if (index < num_nodes) {
            current->right = nodes[index++];
            enqueue(current->right, &front);
        }
    }

    return root;
}

int rebuild_tree(struct process **root) {
     if (is_complete(*root) && is_sorted(*root)) {
        return 0;  /* Tree is already complete and sorted in level order */
    }

    /* Collect all nodes in level order */
    int total_nodes = num_nodes(*root);
    
    struct process *nodes[total_nodes];
    int index = 0;
    
    collect_nodes(*root, nodes, &index);

    /* Sort nodes by pid (in ascending order) */
    for (int i = 0; i < total_nodes - 1; i++) {
        for (int j = i + 1; j < total_nodes; j++) {
            if (nodes[i]->pid > nodes[j]->pid) {
                struct process *temp = nodes[i];
                
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }

    /* Rebuild the tree from the sorted nodes */
    *root = rebuild_from_sorted_nodes(nodes, total_nodes);

    return 1;  // The tree has been rebuilt
}

/* Helper function to replace a node with its rightmost child */
static void replace_with_rightmost(struct process **root, struct process *node_to_delete) {
    /* Collect nodes in level-order */
    struct process *nodes[256];
    int index = 0;
    collect_nodes(*root, nodes, &index);

    /* Find the last node (rightmost leaf node) */
    struct process *last_node = nodes[index - 1];

    /* Replace the node_to_delete with last_node */
    if (node_to_delete == *root) {
        *root = last_node;
    } else {
        struct queue *front = NULL;
        enqueue(*root, &front);
        
        while (front != NULL) {
            struct process *current = dequeue(&front);
            
            if (current != NULL) {
                if (current->left == node_to_delete) {
                    current->left = NULL;
                    break;
                } else if (current->right == node_to_delete) {
                    current->right = NULL;
                    break;
                }
                
                enqueue(current->left, &front);
                enqueue(current->right, &front);
            }
        }
    }

    /* Set the last node's left and right children to NULL (as it's a leaf) */
    last_node->left = NULL;
    last_node->right = NULL;
}

int kill(struct process **root, int pid) {
    if (*root == NULL) {
        return 0;  /* Tree is empty */
    }

    struct process *node_to_delete = NULL;
    struct queue *front = NULL;
    enqueue(*root, &front);

    /* Find the node to be deleted (level-order traversal) */
    while (front != NULL) {
        struct process *current = dequeue(&front);
        
        if (current != NULL) {
            if (current->pid == pid) {
                node_to_delete = current;
                
                break;
            }
            
            enqueue(current->left, &front);
            enqueue(current->right, &front);
        }
    }

    if (node_to_delete == NULL) {
        return 0;  /* Node with the given PID not found */
    }

    /* Handle different deletion cases */
    struct process *parent = NULL;
    
    if (node_to_delete == *root) {
        /* Special case: if the node to delete is the root */
        *root = NULL;
    } else {
        struct queue *front = NULL;
        enqueue(*root, &front);
        
        while (front != NULL) {
            struct process *current = dequeue(&front);
            
            if (current != NULL) {
                if (current->left == node_to_delete) {
                    parent = current;
                    current->left = NULL;
                    
                    break;
                } else if (current->right == node_to_delete) {
                    parent = current;
                    current->right = NULL;
                    
                    break;
                }
                
                enqueue(current->left, &front);
                enqueue(current->right, &front);
            }
        }
    }

    /* Replace the deleted node with the last node in the tree */
    if (node_to_delete != *root) {
        replace_with_rightmost(root, node_to_delete);
    }

    /* Free the memory of the deleted node */
    free(node_to_delete);
    node_to_delete = NULL;

    /* Rebuild the tree to ensure it's complete and sorted */
    /* Collect all nodes in level-order and then sort them by PID */
    int total_nodes = num_nodes(*root);
    struct process *nodes[total_nodes];
    int index = 0;
    
    collect_nodes(*root, nodes, &index);

    /* Sort nodes by PID in ascending order (bubble sort or any efficient algorithm can be used) */
    for (int i = 0; i < total_nodes - 1; i++) {
        for (int j = i + 1; j < total_nodes; j++) {
            if (nodes[i]->pid > nodes[j]->pid) {
                struct process *temp = nodes[i];
                
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }

    /* Rebuild the tree from the sorted nodes */
    struct process *new_root = nodes[0];
    struct queue *q = NULL;
    enqueue(new_root, &q);
    
    index = 1;

    while (index < total_nodes) {
        struct process *current = dequeue(&q);
        
        if (index < total_nodes) {
            current->left = nodes[index++];
            enqueue(current->left, &q);
        }
        
        if (index < total_nodes) {
            current->right = nodes[index++];
            enqueue(current->right, &q);
        }
    }

    /* Set the new tree root */
    *root = new_root;

    return 1;  /* Successfully deleted and the tree is now complete and sorted */
}