/* 
 * process.c
 * implements a binary tree, uses it for making a process tree
 * Ignacio Poggi, 20251028
 */

#include <stdio.h>
#include <stdlib.h>

#include "process.h"

struct process *make_process(int pid, int mem_used) {
    struct process *np = NULL;
    
    if (pid >= 0 && mem_used > 0) {
        np = (struct process *)malloc(sizeof(struct process));
        
        if (np == NULL) {
            perror("Cannot allocate memory for new process.\n");
            
            exit(EXIT_FAILURE);
        }
        
        np->pid = pid;
        np->mem_used = mem_used;
        np->left = NULL;
        np->right = NULL;
    }
    
    return np;
}

static void helper_print_postorder(struct process *root) {
    if (root != NULL) {
        helper_print_postorder(root->left);
        helper_print_postorder(root->right);
        
        printf("%d ", root->pid);
    }
}

void print_postorder(struct process *root) {
    printf("%s", "Postorder: ");
    
    helper_print_postorder(root);
    
    printf("\n");
}

static void helper_print_inorder(struct process *root) {
    if (root != NULL) {
        helper_print_inorder(root->left);
        
        printf("%d ", root->pid);
        
        helper_print_inorder(root->right);
    }
}

void print_inorder(struct process *root) {
    printf("%s", "Inorder: ");
    
    helper_print_inorder(root);
    
    printf("\n");
}

static int height(struct process *root) {
    int h = 0;
    
    if (root != NULL) {
        int lh = height(root->left);
        int rh = height(root->right);
        
        int max = (lh > rh) ? lh : rh;
        
        h = 1 + max;
    }
    
    return h;
}

static void print_level(struct process *root, int level) {
    if (root != NULL) {
        if (level == 1) {
            printf("%d ", root->pid);
        } else {
            print_level(root->left, level - 1);
            print_level(root->right, level - 1);
        }
    }
}

static void print_levels(struct process *root, int curr_level, int height) {
    if (curr_level <= height) {
        print_level(root, curr_level);
        
        print_levels(root, curr_level + 1, height);
    }
}

void print_levelorder(struct process *root) {
    printf("%s", "Levelorder: ");
    
    int h = height(root);
    
    print_levels(root, 1, h);
    
    printf("\n");
}

int num_nodes(struct process *root) {
    int total_nodes = 0;
    
    if (root != NULL) {
        total_nodes += 1 + num_nodes(root->left) + num_nodes(root->right);
    }
    
    return total_nodes;
}

static int helper_is_complete(struct process *root, int index, int total) {
    int cmp = 1;
    
    if (root != NULL) {
        if (index < total) {
            cmp = helper_is_complete(root->left, 2 * index + 1, total) &&
                    helper_is_complete(root->right, 2 * index + 2, total);
        } else {
            cmp = 0;
        }
    }
    
    return cmp;
}

int is_complete(struct process *root) {
    int complete = 1;
    
    if (root != NULL) {
        int nodes = num_nodes(root);
        
        complete = helper_is_complete(root, 0, nodes);
    }
    
    return complete;
}

void remove_all(struct process **root) {
    if (root != NULL && *root != NULL) {
        remove_all(&(*root)->left);
        remove_all(&(*root)->right);
        
        free(*root);
        *root = NULL;
    }
}

int contains_pid(struct process *root, int value) {
    int is_contained = 0;
    
    if (root != NULL) {
        if (root->pid == value) {
            is_contained = 1;
        } else {
            is_contained = contains_pid(root->left, value) || contains_pid(root->right, value);
        }
    }
    
    return is_contained;
}

int total_mem(struct process *root) {
    int tm = 0;
    
    if (root != NULL) {
        tm += root->mem_used + total_mem(root->left) + total_mem(root->right);
    }
    
    return tm;
}

int can_add(struct process *root, struct process *new_node, int max_mem) {
    int ca = 0;
    
    if (new_node != NULL) {
        int not_contained = (contains_pid(root, new_node->pid) == 0);
        int tm_pnode = total_mem(root) + new_node->mem_used;
        
        ca = not_contained && (tm_pnode <= max_mem);
    }
    
    return ca;
}

static int insert_at_level(struct process *root, struct process *to_add, int level) {
    int ial = 0;
    
    if (root != NULL) {
        if (level == 1) {
            if (root->left == NULL) {
                root->left = to_add;
                
                ial = 1;
            } else if (root->right == NULL) {
                root->right = to_add;
                
                ial = 1;
            }
        } else {
            if (insert_at_level(root->left, to_add, level - 1)) {
                ial = 1;
            }
            
            if (insert_at_level(root->right, to_add, level - 1)) {
                ial = 1;
            }
        }
    }
    
    return ial;
}

static void helper_insert_level(struct process *root, struct process *to_add, int level, int max_level, int *inserted) {
    if (*inserted == 0 && level <= max_level && insert_at_level(root, to_add, level)) {
        *inserted = 1;
        
        helper_insert_level(root, to_add, level + 1, max_level, inserted);
    }
}

void insert_levelorder(struct process **root, struct process *to_add, int max_mem) {
    if (root != NULL) {
        int ca = can_add(*root, to_add, max_mem);
        
        if (ca == 1) {
            if (*root == NULL) {
                *root = to_add;
            } else {
                int h = height(*root);
                int inserted = 0;
                
                helper_insert_level(*root, to_add, 1, h + 1, &inserted);
            }
        }
    }
}

struct process *create_tree(int first_pid, int max_mem, int mem_per_proc, int num_nodes) {
    struct process *first = make_process(first_pid, mem_per_proc);
    
    if (num_nodes > 1) {
        struct process *next = create_tree(first_pid + 1, max_mem, mem_per_proc, num_nodes - 1);
        
        insert_levelorder(&first, next, max_mem);
    } else {
        insert_levelorder(NULL, first, max_mem);
    }
    
    return first;
}

void sorted_recursive(struct queue **btqueue, int lastvalue, int* not_sorted) {
	/* Traverse the tree lengthwise. If the last value is smaller than the current, we are sorted. Else, we are not. */
	int thisvalue;
	
	if (*btqueue == NULL) {
		return;
	}
	
	struct process *node = dequeue(btqueue);
	
	if(node == NULL) {
		return;
	}
	
	thisvalue = node->pid;
	
	if(thisvalue < lastvalue) {
		*not_sorted = 1;
	}
	
	if(node->left) {
		enqueue(node->left, btqueue);
	}
	
	if(node->right) {
		enqueue(node->right, btqueue);
	}
	
	sorted_recursive(btqueue, thisvalue, not_sorted);
}

int is_sorted(struct process *root) {
	/* Use a queue - verify that the next element in the queue is larger than our preceding (or null). */
	struct queue *pointme = NULL;
	struct queue **bt_queue = &pointme;
	enqueue(root, bt_queue);
	
	int unsorted = 0;
	int *not_sorted = &unsorted;
	
	sorted_recursive(bt_queue, 0, not_sorted);
	
	if (unsorted) {
		return 0;
	} else {
		return 1;
	}
}

struct process *get_min(struct process *root, int smallest_val) {
    struct process *proc_min = NULL;
    
    if (root != NULL && is_sorted(root) == 1) {
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

int rebuild_tree(struct process **root) {
    return 0;
}

int kill(struct process **root, int pid) {
    return 0;
}


