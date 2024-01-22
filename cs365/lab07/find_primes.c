#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#include "is_prime.h"

typedef struct {
	int capacity;
	int num_found;
	int *data;

	pthread_mutex_t lock;
} PrimeList ;

/*
 * Create a PrimeList with enough capacity to store given
 * number of primes.
 */
PrimeList *primelist_alloc(int capacity) {
	PrimeList *list = (PrimeList *)malloc(sizeof(PrimeList));
	
	if (list == NULL) {
		fprintf(stderr, "Cannot allocate memory for new list.\n");
		
		exit(EXIT_FAILURE);
	}
	
	list->capacity = capacity;
	list->num_found = 0;
	list->data = (int *)malloc(capacity * sizeof(int));
	
	if (list->data == NULL) {
		fprintf(stderr, "Cannot allocate memory for new list data.\n");
		
		exit(EXIT_FAILURE);
	}

	int ml = pthread_mutex_init(&list->lock, NULL);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot initialize mutex lock of list.\n");
		
		exit(EXIT_FAILURE);
	}

	return list;
}

void primelist_dealloc(PrimeList *list) {
	free(list->data);
	list->data = NULL;
	
	int md = pthread_mutex_destroy(&list->lock);
	
	if (md != 0) {
		fprintf(stderr, "Cannot destroy mutex lock of list.\n");
		
		exit(EXIT_FAILURE);
	}
	
	free(list);
	list = NULL;
}

/*
 * Use this function to add a prime to the PrimeList.
 * This function must be thread-safe!
 * Use the PrimeList's mutex to guard the critical section
 * (the code that will access the PrimeList's fields).
 */
void primelist_append(PrimeList *list, int prime) {
	int ml = pthread_mutex_lock(&list->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot lock mutex of list.\n");
		
		exit(EXIT_FAILURE);
	}
	
	/* Make sure there is room to store one more value */
	if (list->num_found < list->capacity) {
		*(list->data + list->num_found) = prime;
		
		list->num_found++;
	}
	
	ml = pthread_mutex_unlock(&list->lock);
	
	if (ml != 0) {
		fprintf(stderr, "Cannot unlock mutex of list.\n");
		
		exit(EXIT_FAILURE);
	}
}

struct Work {
	PrimeList *list;
	int thread_num;
	int start;
	int end;
};

void *worker(void *arg) {
	struct Work *w = (struct Work *)arg;

	printf("Thread %i: range is %i..%i\n", w->thread_num, w->start, w->end);
	
	for (int i = w->start; i < w->end; i++) {
		if (is_prime(i)) {
			primelist_append(w->list, i);
		}
	}

	return NULL;
}

int main(void) {
	int min = 0, max = 0;
	int num_threads = 0;

	printf("%s", "Min: ");
	scanf("%i", &min);
	
	printf("%s", "Max: ");
	scanf("%i", &max);
	
	printf("%s", "Number of threads: ");
	scanf("%i", &num_threads);
	
	int est_num_primes = (int)((max / log(max)) * 1.4);
	
	printf("Estimated number of primes is %i\n", est_num_primes);

	/* Use this data structure to store all of the primes discovered */
	PrimeList *list = primelist_alloc(est_num_primes);

	/* Use threads to find all primes in range, add them to the PrimeList */
	int n = (max - min) + 1;
	int chunk_size = n / num_threads;

	struct Work *work_list = (struct Work *)malloc(sizeof(struct Work) * num_threads);
	
	if (work_list == NULL) {
		fprintf(stderr, "Cannot allocate memory for new work list.\n");
		
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < num_threads; i++) {
		(work_list + i)->list = list;
		(work_list + i)->thread_num = i;
		(work_list + i)->start = min + (i * chunk_size);
		(work_list + i)->end = min + (i + 1) * chunk_size;
		
		if (i == num_threads-1) {
			/* Last thread gets excess */
			(work_list + i)->end += n % num_threads;
		}
	}

	/* Start threads */
	pthread_t *thr = (pthread_t *)malloc(sizeof(pthread_t) * num_threads);
	
	if (thr == NULL) {
		fprintf(stderr, "Cannot allocate memory for new threads list.\n");
		
		exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < num_threads; i++) {
		int th = pthread_create(thr + i, NULL, &worker, work_list + i);
		
		if (th != 0) {
			fprintf(stderr, "Cannot create thread.\n");
		
			exit(EXIT_FAILURE);
		}
	}

	/* Wait for threads to exit */
	for (int i = 0; i < num_threads; i++) {
		int th = pthread_join(*(thr + i), NULL);
		
		if (th != 0) {
			fprintf(stderr, "Cannot join thread.\n");
		
			exit(EXIT_FAILURE);
		}
		
		printf("Thread %i finished\n", i);
	}

	/* Print out all primes found in range (once all threads have completed) */
	printf("%i primes found\n", list->num_found);
	
	for (int i = 0; i < list->num_found; i++) {
		printf("%i\n", *(list->data + i));
	}
	
	free(work_list);
	work_list = NULL;
	
	free(thr);
	thr = NULL;
	
	primelist_dealloc(list);

	return EXIT_SUCCESS;
}