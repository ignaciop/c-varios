/*
 * Generic queue data type.
 */

#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_node {
	void *item;
	struct queue_node *next;
} queue_node_t;

/*
 * Queue data structure.
 */
typedef struct queue {
	queue_node_t *head, *tail;
} queue_t;

/*
 * Initialize the queue object whose pointer
 * is given.
 *
 * Params:
 *   q - pointer to a queue_t object that should
 *       be initialized
 */
void queue_init(queue_t *q);

/*
 * Return whether or not the given queue is
 * empty.
 *
 * Params:
 *   q - pointer to a queue_t object
 *
 * Returns:
 *   Non-zero (true) if the queue is empty,
 *   zero (false) if the queue is not empty.
 */
int queue_is_empty(queue_t *q);

/*
 * Enqueue given item onto given queue.
 * The item becomes the new tail item.
 *
 * Params:
 *   q -    pointer to a queue_t object
 *   item - pointer value that refers to the item to be added to the queue
 */
void queue_enqueue(queue_t *q, void *item);

/*
 * Dequeue the current head item from the given queue,
 * and return a pointer to that item.
 * Note: this function should NOT be called if
 * the queue is empty!
 *
 * Params:
 *   q -    pointer to a queue_t object
 *
 * Returns:
 *   Pointer to the head item (the item which was enqueued
 *   least recently.)
 */
void *queue_dequeue(queue_t *q);

#endif /* QUEUE_H */