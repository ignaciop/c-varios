#ifndef REQUESTS_QUEUE_H
#define REQUESTS_QUEUE_H

#include <pthread.h> /* pthread functions and data structures */

/* format of a single request. */
struct request {
    int number; /* number of the request */
    struct request *next; /* pointer to next request, NULL if none. */
};

/* structure for a requests queue */
struct requests_queue {
    struct request *requests; /* head of linked list of requests. */
    struct request *last_request; /* pointer to last request. */
    int num_requests; /* number of requests in queue. */
    pthread_mutex_t *p_mutex; /* queue's mutex. */
    pthread_cond_t *p_cond_var; /* queue's condition variable. */
};

/*
 * create a requests queue. associate it with the given mutex
 * and condition variables.
 */
struct requests_queue *init_requests_queue(pthread_mutex_t *p_mutex, pthread_cond_t *p_cond_var);

/* add a request to the requests list */
void add_request(struct requests_queue* queue, int request_num);

/* get the first pending request from the requests list */
struct request *get_request(struct requests_queue *queue);

/* get the number of requests in the list */
int get_requests_number(struct requests_queue *queue);

/* free the resources taken by the given requests queue */
void delete_requests_queue(struct requests_queue *queue);

#endif /* REQUESTS_QUEUE_H */