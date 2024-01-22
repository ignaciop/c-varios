#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct {
	/* data describing this thread's subproblem */
	int value;

	/* data that is the result of this thread's computation */
	int result;
} Work;

/* thread start function */
void *worker(void *arg) {
	Work *work = (Work *)arg;

	printf("My data is %i\n", work->value);

	/* compute a result */
	work->result = work->value * 2;

	return NULL;
}

int main(void) {
	Work *work_data = malloc(sizeof(Work) * NUM_THREADS);
	
	if (work_data == NULL) {
		fprintf(stderr, "Cannot allocate memory for work_data.\n");
		
		exit(EXIT_FAILURE);
	}

	/* assign work */
	work_data[0].value = 1;
	work_data[1].value = 2;
	work_data[2].value = 3;
	work_data[3].value = 4;

	printf("%s\n", "About to create threads...");

	/* create threads */
	pthread_t threads[NUM_THREADS] = {0};
	int thv = 0;
	
	for (int i = 0; i < NUM_THREADS; i++) {
		thv = pthread_create(&threads[i], NULL, &worker, &work_data[i]);
		
		if (thv != 0) {
			fprintf(stderr, "Cannot create thread %d.\n", i);
		
			exit(EXIT_FAILURE);
		}
	}

	printf("%s\n", "Waiting for threads...");

	/* wait for threads to finish */
	for (int i = 0; i < NUM_THREADS; i++) {
		thv = pthread_join(threads[i], NULL);
		
		if (thv != 0) {
			fprintf(stderr, "Cannot join thread %d.\n", i);
		
			exit(EXIT_FAILURE);
		}
	}

	printf("%s\n", "Threads are finished");
	
	for (int i = 0; i < NUM_THREADS; i++) {
		printf("Result: %i\n", work_data[i].result);
	}
	
	free(work_data);
	work_data = NULL;

	return EXIT_SUCCESS;
}