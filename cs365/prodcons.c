#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "queue.h"

typedef struct {
	queue_t q;
	int max;   /* max number of items */
	int count; /* current number of items */

	pthread_mutex_t lock;
	pthread_cond_t cond;
} BoundedQueue;

void boundedqueue_init(BoundedQueue *bq, int max);
void boundedqueue_enqueue(BoundedQueue *bq, void *item);
void *boundedqueue_dequeue(BoundedQueue *bq);

/* producer is fast */
void *producer(void *arg) {
	BoundedQueue *bq = (BoundedQueue *)arg;
	
	for (int i = 0; i < 26; i++) {
		char val = 'A' + i;
		
		char *item = (char *)malloc(sizeof(char));
		
		if (item == NULL) {
			fprintf(stderr, "Cannot allocate memory for queue node.\n");
		
			exit(EXIT_FAILURE);
		}
		
		*item = val;
		
		boundedqueue_enqueue(bq, item);
		
		printf("sent %c\n", val);
	}
	return NULL;
}

/* consumer is slow */
void *consumer(void *arg) {
	BoundedQueue *bq = (BoundedQueue *)arg;
	
	int done = 0;
	
	while (!done) {
		char *item = boundedqueue_dequeue(bq);
		
		printf("received %c\n", *item);
		
		if (*item == 'Z') {
			done = 1;
		}
		
		free(item);
		item = NULL;
		
		sleep(1);
	}
	
	return NULL;
}

int main(void) {
	BoundedQueue *bq = malloc(sizeof(BoundedQueue));
	
	if (bq == NULL) {
		fprintf(stderr, "Cannot allocate memory for bounded queue.\n");
		
		exit(EXIT_FAILURE);
	}
	
	boundedqueue_init(bq, 5);

	pthread_t thread1, thread2;

	int tv = pthread_create(&thread1, NULL, &producer, bq);
	
	if (tv != 0) {
		fprintf(stderr, "Cannot create producer thread.\n");
		
		exit(EXIT_FAILURE);
	}
	
	tv = pthread_create(&thread2, NULL, &consumer, bq);
	
	if (tv != 0) {
		fprintf(stderr, "Cannot create consumer thread.\n");
		
		exit(EXIT_FAILURE);
	}
	
	int tj = pthread_join(thread1, NULL);
	
	if (tj != 0) {
		fprintf(stderr, "Cannot join producer thread.\n");
		
		exit(EXIT_FAILURE);
	}
	
	tj = pthread_join(thread2, NULL);
	
	if (tj != 0) {
		fprintf(stderr, "Cannot join consumer thread.\n");
		
		exit(EXIT_FAILURE);
	}

	printf("%s\n", "done");
	
	int cd = pthread_cond_destroy(&bq->cond);
	
	if (cd != 0) {
		fprintf(stderr, "Cannot destroy queue condition variable.\n");
		
		exit(EXIT_FAILURE);
	}
	
	int md = pthread_mutex_destroy(&bq->lock);
	
	if (md != 0) {
		fprintf(stderr, "Cannot destroy queue mutex.\n");
		
		exit(EXIT_FAILURE);
	}
	
	free(bq);
	bq = NULL;

	return EXIT_SUCCESS;
}

void boundedqueue_init(BoundedQueue *bq, int max) {
	queue_init(&bq->q);
	
	bq->max = max;
	bq->count = 0;
	
	int ml = pthread_mutex_init(&bq->lock, NULL);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot init mutex lock.\n");
		
		exit(EXIT_FAILURE);
	}
	
	int cv = pthread_cond_init(&bq->cond, NULL);
	
	if (cv != 0) {
		fprintf(stderr, "Cannot init condition variable.\n");
		
		exit(EXIT_FAILURE);
	}
}

void boundedqueue_enqueue(BoundedQueue *bq, void *item) {
	int ml = pthread_mutex_lock(&bq->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot lock mutex.\n");
		
		exit(EXIT_FAILURE);
	}

	while (bq->count >= bq->max) {
		int cw = pthread_cond_wait(&bq->cond, &bq->lock);
		
		if (cw != 0) {
			fprintf(stderr, "Cannot wait condition variable.\n");
		
			exit(EXIT_FAILURE);
		}
	}

	queue_enqueue(&bq->q, item);
	
	bq->count++;
	
	int cb = pthread_cond_broadcast(&bq->cond); /* wake up consumer */
	
	if (cb != 0) {
		fprintf(stderr, "Cannot broadcast condition variable.\n");
		
		exit(EXIT_FAILURE);
	}

	ml = pthread_mutex_unlock(&bq->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot unlock mutex.\n");
		
		exit(EXIT_FAILURE);
	}
}

void* boundedqueue_dequeue(BoundedQueue *bq) {
	int ml = pthread_mutex_lock(&bq->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot lock mutex.\n");
		
		exit(EXIT_FAILURE);
	}

	while (bq->count == 0) {
		int cw = pthread_cond_wait(&bq->cond, &bq->lock);
		
		if (cw != 0) {
			fprintf(stderr, "Cannot wait condition variable.\n");
		
			exit(EXIT_FAILURE);
		}
	}

	void *result = queue_dequeue(&bq->q);
	
	bq->count--;
	
	int cb = pthread_cond_broadcast(&bq->cond); /* wake up consumer */
	
	if (cb != 0) {
		fprintf(stderr, "Cannot broadcast condition variable.\n");
		
		exit(EXIT_FAILURE);
	}

	ml = pthread_mutex_unlock(&bq->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot unlock mutex.\n");
		
		exit(EXIT_FAILURE);
	}

	return result;
}