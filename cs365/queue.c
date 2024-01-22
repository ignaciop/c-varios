/*
 * Generic queue data type.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"

void queue_init(queue_t *q) {
	q->head = q->tail = NULL;
}

int queue_is_empty(queue_t *q) {
	return (q->head == NULL);
}

void queue_enqueue(queue_t *q, void *item) {
	queue_node_t *node = (queue_node_t *)malloc(sizeof(queue_node_t));
	
	if (node == NULL) {
		fprintf(stderr, "Cannot allocate memory for queue node.\n");
		
		exit(EXIT_FAILURE);
	}
	
	node->item = item;
	node->next = NULL;

	if (q->tail != NULL) {
		q->tail->next = node;
		q->tail = node;
	} else {
		q->head = q->tail = node;
	}
}

void *queue_dequeue(queue_t *q) {
	assert(!queue_is_empty(q));

	void *item = q->head->item;
	
	queue_node_t *old_head = q->head;
	
	q->head = q->head->next;
	
	free(old_head);
	old_head = NULL;
	
	if (q->head == NULL) {
		q->tail = NULL;
	}

	return item;
}