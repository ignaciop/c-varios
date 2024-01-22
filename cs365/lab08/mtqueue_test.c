#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#include "mtqueue.h"

#define NUM_ITEMS 26

void *producer_run(void *arg) {
	MTQueue *q = (MTQueue *)arg;

	for (int i = 0; i < NUM_ITEMS; i++) {
		char *item = malloc(2);
		
		if (item == NULL) {
			fprintf(stderr, "Cannot allocate memory for new item.\n");
		
			exit(EXIT_FAILURE);
		}
		
		item[0] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i];
		item[1] = '\0';
		
		printf("Produce %s\n", item);
		
		mtqueue_enqueue(q, item);
		
		usleep(100000); /* sleep for .1s */
	}

	/* Wait for queue to become empty */
	printf("%s\n", "Producer waiting for queue to become empty");

	mtqueue_wait_until_empty(q);

	printf("%s\n", "Producer finished");

	return NULL;
}

void *consumer_run(void *arg) {
	MTQueue *q = (MTQueue *)arg;

	while (1) {
		void *item = mtqueue_dequeue(q);
		
		printf("Consumed: %s\n", (char *)item);
		
		free(item);
		item = NULL;
		
		usleep(500000);
	}
}

int main(void) {
	MTQueue *q = mtqueue_create();
	
	pthread_t producer;
	pthread_t consumer[2];

	int t1 = pthread_create(&producer, NULL, producer_run, q);
	
	if (t1 != 0) {
		fprintf(stderr, "Cannot create producer thread.\n");
		
		exit(EXIT_FAILURE);
	}
	
	int t2 = pthread_create(&consumer[0], NULL, consumer_run, q);
	
	if (t2 != 0) {
		fprintf(stderr, "Cannot create first consumer thread.\n");
		
		exit(EXIT_FAILURE);
	}
	
	int t3 = pthread_create(&consumer[1], NULL, consumer_run, q);

	if (t3 != 0) {
		fprintf(stderr, "Cannot create second consumer thread.\n");
		
		exit(EXIT_FAILURE);
	}
	
	int tj = pthread_join(producer, NULL);
	
	if (tj != 0) {
		fprintf(stderr, "Cannot join producer thread.\n");
		
		exit(EXIT_FAILURE);
	}
	
	printf("%s\n", "Producer exited");

	/* Don't wait for the consumers to finish */
	
	int cd = pthread_cond_destroy(&q->cond);
	
	if (cd != 0) {
		fprintf(stderr, "Cannot destroy condition variable for queue.\n");
		
		exit(EXIT_FAILURE);
	}
	
	int md = pthread_mutex_destroy(&q->lock);
	
	if (md != 0) {
		fprintf(stderr, "Cannot destroy mutex for queue.\n");
		
		exit(EXIT_FAILURE);
	}

	free(q);
	q = NULL;
	
	return EXIT_SUCCESS;
}