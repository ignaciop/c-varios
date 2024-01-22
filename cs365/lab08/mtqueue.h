#ifndef MTQUEUE_H
#define MTQUEUE_H

#include <pthread.h>

typedef struct MTQueueNode_ {
	void *item;
	struct MTQueueNode_ *next;
} MTQueueNode;

typedef struct {
	MTQueueNode *head, *tail;

	pthread_mutex_t lock;
	pthread_cond_t cond;
} MTQueue;

MTQueue *mtqueue_create(void);
void mtqueue_enqueue(MTQueue *q, void *item);
void *mtqueue_dequeue(MTQueue *q);
void mtqueue_wait_until_empty(MTQueue *q);

#endif