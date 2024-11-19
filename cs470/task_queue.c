#include <stdio.h>
#include <stdlib.h>

#include "task_queue.h"

struct task_queue *task_queue_create(void) {
    struct task_queue *q = (struct task_queue *)malloc(sizeof(struct task_queue));
    
    if (q == NULL) {
        perror("Error allocating memory for new task queue");
        
        exit(EXIT_FAILURE);    
    }
    
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    
    return q;
}

void task_queue_enqueue(struct task_queue *q, char action, int num) {
    if (q == NULL) {
        return;
    }
    
    struct task *new_task = (struct task *)malloc(sizeof(struct task));
    
    if (new_task == NULL) {
        perror("Error allocating memory for new task");
        
        exit(EXIT_FAILURE);    
    }
    
    new_task->action = action;
    new_task->num = num;
    new_task->next = NULL;
    
    if (task_queue_size(q) == 0) { // First insertion
        q->head = q->tail = new_task;
    } else {
        q->tail->next = new_task;
        q->tail = new_task;
    }
    
    q->size++;
}

struct task *task_queue_dequeue(struct task_queue *q) {
    if (q == NULL || task_queue_size(q) == 0) {
        return NULL;
    }
    
    struct task *del_task = q->head;
    
    q->head = q->head->next;
    
    if (q->head == NULL) {
        q->tail = NULL;  // If the queue becomes empty, reset tail to NULL
    }
    
    q->size--;
    
    del_task->next = NULL;
    
    return del_task;
}

void task_queue_print(struct task_queue *q) {
	struct task *curr_task = q->head;
	
	printf("%s", (curr_task == NULL) ? "[  " : "[");
	
	while (curr_task != NULL) {
		printf("<%c, %d>, ", curr_task->action, curr_task->num);
		
		curr_task = curr_task->next;
	}
	
	printf("%s\n", "\b\b]");
}

size_t task_queue_size(struct task_queue *q) {
    size_t qs = (q == NULL) ? 0 : q->size;
    
    return qs;
}

void task_queue_destroy(struct task_queue **q) {
    if (q == NULL || *q == NULL) {
        return;
    }
    
    struct task *curr_task = (*q)->head;
    
    while (curr_task != NULL) {
        struct task *next_task = curr_task->next;
        
        free(curr_task);
        curr_task = next_task;
    }
    
    free(*q);
    *q = NULL;
}