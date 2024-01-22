#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
	int count;
	pthread_mutex_t lock;
	pthread_cond_t cond;
} Counter;

void counter_init(Counter *c);
int counter_get(Counter *c);
void counter_incr(Counter *c);
void counter_wait_threshold(Counter *c, int threshold);

void *worker(void *arg) {
	Counter *c = (Counter *)arg;

	for (int i = 0; i < 10; i++) {
		printf("%s\n", "tick");
		
		counter_incr(c);
		
		sleep(1);
	}

	return NULL;
}

void *worker2(void *arg) {
	Counter *c = (Counter *)arg;
	
	counter_wait_threshold(c, 6);
	
	printf("%s\n", "counter has reached 6!");
	
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
	
	tv = pthread_create(&thread2, NULL, &worker2, c);
	
	if (tv != 0) {
		fprintf(stderr, "Cannot create thread.\n");
		
		exit(EXIT_FAILURE);
	}

	/* wait for the threads to complete */
	int tj = pthread_join(thread2, NULL);
	
	if (tj != 0) {
		fprintf(stderr, "Cannot join thread.\n");
		
		exit(EXIT_FAILURE);
	}
	
	printf("%s\n", "thread 2 is finished");
	
	tj = pthread_join(thread1, NULL);
	
	if (tj != 0) {
		fprintf(stderr, "Cannot join thread.\n");
		
		exit(EXIT_FAILURE);
	}
	
	printf("%s\n", "thread 1 is finished");

	printf("final count is %d\n", c->count);
	
	int cd = pthread_cond_destroy(&c->cond);
	
	if (cd != 0) {
		fprintf(stderr, "Cannot destroy condition variable.\n");
		
		exit(EXIT_FAILURE);
	}
	
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
	
	int cv = pthread_cond_init(&c->cond, NULL);
	
	if (cv != 0) {
		fprintf(stderr, "Cannot init condition variable.\n");
		
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
	
	int cb = pthread_cond_broadcast(&c->cond);
	
	if (cb != 0) {
		fprintf(stderr, "Cannot broadcast condition variable.\n");
		
		exit(EXIT_FAILURE);
	}
	
	ml = pthread_mutex_unlock(&c->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot unlock mutex.\n");
		
		exit(EXIT_FAILURE);
	}
}

void counter_wait_threshold(Counter *c, int threshold) {
	int ml = pthread_mutex_lock(&c->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot lock mutex.\n");
		
		exit(EXIT_FAILURE);
	}

	while (c->count < threshold) {
		int cw = pthread_cond_wait(&c->cond, &c->lock);
		
		if (cw != 0) {
			fprintf(stderr, "Cannot wait condition variable.\n");
		
			exit(EXIT_FAILURE);
		}
	}
	/* now c->count >= threshold */

	ml = pthread_mutex_unlock(&c->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot unlock mutex.\n");
		
		exit(EXIT_FAILURE);
	}
}