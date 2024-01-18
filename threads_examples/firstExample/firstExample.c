/*
 * A simple example to demonstrate the basics of PThreads API.
 *
 * Author: Andre Leon S. Gradvohl, Dr.
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS	5

/*
 * A thread that prints a message in the screen.
 */
void *print_hello(void *args) {
	pthread_t id = pthread_self();
	
	fprintf(stdout, "Hello world! My thread id: #%ld\n", id);

	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	pthread_t threads[NUM_THREADS] = {0};
	
	int rc;

	/*
	 * Creating threads.
	 */
	for (int t = 0; t < NUM_THREADS; t++) {
		fprintf(stdout, "Starting thread %d\n", t);
	
		rc = pthread_create(&threads[t], NULL, print_hello, NULL);

		if (rc != 0) {
	  		fprintf(stderr, "ERROR: pthread_create() returns %d\n", rc);
	  
	  		exit(EXIT_FAILURE);
		}
	}

	/*
	 * Joining threads.
	 */
	 
	for (int t = 0; t < NUM_THREADS; t++) {
		printf("Joining thread #%d\n", t);
	
		rc = pthread_join(threads[t], NULL);

		if (rc != 0) {
	  		fprintf(stderr, "ERROR: pthread_join() returns %d\n", rc);
	  
	  		exit(EXIT_FAILURE);
		}
	}

	return EXIT_SUCCESS;
}