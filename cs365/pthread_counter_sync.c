#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
	int count;
	pthread_mutex_t lock;
} Counter;

void counter_init(Counter *c);
int counter_get(Counter *c);
void counter_incr(Counter *c);

void *worker(void *arg) {
	Counter *c = (Counter *)arg;

	for (int i = 0; i < 1000000; i++) {
		counter_incr(c);
	}

	return NULL;
}

int main(void) {
	pthread_t thread1, thread2;

	Counter *c = malloc(sizeof(Counter));
	
	if (c == NULL) {
		fprintf(stderr, "Cannot allocate memory for counter.\n");
		
		exit(EXIT_FAILURE);
	}
	
	counter_init(c);

	int tv = pthread_create(&thread1, NULL, &worker, c);
	
	if (tv != 0) {
		fprintf(stderr, "Cannot create thread.\n");
		
		exit(EXIT_FAILURE);
	}
	
	tv = pthread_create(&thread2, NULL, &worker, c);
	
	if (tv != 0) {
		fprintf(stderr, "Cannot create thread.\n");
		
		exit(EXIT_FAILURE);
	}

	/* wait for the threads to complete */
	int tj = pthread_join(thread1, NULL);
	
	if (tj != 0) {
		fprintf(stderr, "Cannot join thread.\n");
		
		exit(EXIT_FAILURE);
	}
	
	tj = pthread_join(thread2, NULL);
	
	if (tj != 0) {
		fprintf(stderr, "Cannot join thread.\n");
		
		exit(EXIT_FAILURE);
	}

	printf("final count is %d\n", c->count);
	
	int md = pthread_mutex_destroy(&c->lock);
	
	if (md != 0) {
		fprintf(stderr, "Cannot destroy mutex.\n");
		
		exit(EXIT_FAILURE);
	}
	
	free(c);
	c = NULL;

	return EXIT_SUCCESS;
}

void counter_init(Counter *c) {
	c->count = 0;
	
	int ml = pthread_mutex_init(&c->lock, NULL);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot init mutex lock.\n");
		
		exit(EXIT_FAILURE);
	}
}

int counter_get(Counter *c) {
	int ml = pthread_mutex_lock(&c->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot lock mutex.\n");
		
		exit(EXIT_FAILURE);
	}
	
	int val = c->count;
	
	ml = pthread_mutex_unlock(&c->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot unlock mutex.\n");
		
		exit(EXIT_FAILURE);
	}
	
	return val;
}

void counter_incr(Counter *c) {
	int ml = pthread_mutex_lock(&c->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot lock mutex.\n");
		
		exit(EXIT_FAILURE);
	}
	
	int val = c->count;
	
	val += 1;
	
	c->count = val;
	
	ml = pthread_mutex_unlock(&c->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot unlock mutex.\n");
		
		exit(EXIT_FAILURE);
	}
}