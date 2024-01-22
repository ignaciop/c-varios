#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "mtqueue.h"

MTQueue *mtqueue_create(void) {
	MTQueue *q = (MTQueue *)malloc(sizeof(MTQueue));
	
	if (q == NULL) {
		fprintf(stderr, "Cannot allocate memory for new queue.\n");
		
		exit(EXIT_FAILURE);
	}

	q->head = q->tail = NULL;

	int ml = pthread_mutex_init(&q->lock, NULL);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot init mutex for new queue.\n");
		
		exit(EXIT_FAILURE);
	}
	
	int cv = pthread_cond_init(&q->cond, NULL);
	
	if (cv != 0) {
		fprintf(stderr, "Cannot init condition variable for new queue.\n");
		
		exit(EXIT_FAILURE);
	}

	return q;
}

void mtqueue_enqueue(MTQueue *q, void *item) {
	int ml = pthread_mutex_lock(&q->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot lock mutex for enqueue.\n");
		
		exit(EXIT_FAILURE);
	}
	
	MTQueueNode *new_node = (MTQueueNode *)malloc(sizeof(MTQueueNode));
	
	if (new_node == NULL) {
		fprintf(stderr, "Cannot allocate memory for new node in queue.\n");
		
		exit(EXIT_FAILURE);
	}
	
	new_node->item = item;
	new_node->next = NULL;
	
	if (q->head == NULL) {
		/* queue is currently empty, node is the new head/tail */
		q->head = q->tail = new_node;
	} else {
		/* queue is nonempty, make the node the new tail node */
		q->tail->next = new_node;
		q->tail = new_node;
	}
	
	/* wake up consumer (if necessary) */
	int cb = pthread_cond_broadcast(&q->cond);
	
	if (cb != 0) {
		fprintf(stderr, "Cannot broadcast condition variable for enqueue.\n");
		
		exit(EXIT_FAILURE);
	}

	ml = pthread_mutex_unlock(&q->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot unlock mutex for enqueue.\n");
		
		exit(EXIT_FAILURE);
	}
}

void *mtqueue_dequeue(MTQueue *q) {
	int ml = pthread_mutex_lock(&q->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot lock mutex for enqueue.\n");
		
		exit(EXIT_FAILURE);
	}
	
	/* wait for queue to be nonempty */
	while (q->head == NULL) {
		int cw = pthread_cond_wait(&q->cond, &q->lock);
		
		if (cw != 0) {
			fprintf(stderr, "Cannot wait condition variable for enqueue.\n");
		
			exit(EXIT_FAILURE);
		}
	}

	MTQueueNode *node = q->head;
	
	q->head = node->next;
	
	void *item = node->item;
	
	free(node);
	node = NULL;
	
	if (q->head == NULL) {
		q->tail = NULL;
		
		/* wake up thread waiting for queue to be empty */
		int cb = pthread_cond_broadcast(&q->cond);
	
		if (cb != 0) {
			fprintf(stderr, "Cannot broadcast condition variable for enqueue.\n");
		
			exit(EXIT_FAILURE);
		}
	}
	
	ml = pthread_mutex_unlock(&q->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot unlock mutex for enqueue.\n");
		
		exit(EXIT_FAILURE);
	}
	
	return item; 
}

void mtqueue_wait_until_empty(MTQueue *q) {
	int ml = pthread_mutex_lock(&q->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot lock mutex for enqueue.\n");
		
		exit(EXIT_FAILURE);
	}
	
	while (q->head != NULL) {
		int cw = pthread_cond_wait(&q->cond, &q->lock);
		
		if (cw != 0) {
			fprintf(stderr, "Cannot wait condition variable for queue.\n");
		
			exit(EXIT_FAILURE);
		}
	}
	
	ml = pthread_mutex_unlock(&q->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot unlock mutex for enqueue.\n");
		
		exit(EXIT_FAILURE);
	}
}