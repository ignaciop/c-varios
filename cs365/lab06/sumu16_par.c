/* Compute the sum of a file full of binary 16-bit integer data,
 * parallel version.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include "common.h"

struct Work {
	uint16_t *data;
	int n;
	uint64_t sum;
};

void *worker(void *p) {
	struct Work *work = (struct Work *)p;

	work->sum = 0ULL;
	
	for (int i = 0; i < work->n; i++) {
		work->sum += work->data[i];
	}

	return NULL;
}

int main(int argc, char **argv)
{
	uint16_t *data;
	size_t size, num_elements;
	uint64_t sum;
	struct mmap_region region;

	if (argc != 2) {
		fprintf(stderr, "Usage: sumu16 <input file>\n");
		
		exit(EXIT_FAILURE);
	}

	/* Find out how large the file is. */
	size = get_file_size(argv[1]);
	
	printf("File is %lu bytes in size\n", size);

	/* Each element (datum) is 16 bits. */
	/* Find out how many elements there are overall. */
	num_elements = size / sizeof(uint16_t);

	/* Map the file data into memory */
	map_file_region(argv[1], size, &region);
	data = region.addr;

	/* Compute the sum */
	size_t chunk_size = num_elements / 8;

	struct Work *w = malloc(8 * sizeof(struct Work));
	
	if (w == NULL) {
		fprintf(stderr, "Cannot allocate memory for struct Work\n");
		
		exit(EXIT_FAILURE);
	}
	
	for (size_t i = 0; i < 8; i++) {
		w[i].data = data + (i * chunk_size);
		
		w[i].n = chunk_size;
		
		if (i == 7) {
			/* Allocate excess elements to last thread */
			w[i].n += (num_elements % 8);
		}
	}

	pthread_t thr[8] = {0};
	int thv = 0;
	
	for (int i = 0; i < 8; i++) {
		thv = pthread_create(&thr[i], NULL, worker, &w[i]);
		
		if (thv != 0) {
			fprintf(stderr, "Cannot create thread %d\n", i);
		
			exit(EXIT_FAILURE);
		}
	}
	
	sum = 0ULL;
	
	for (int i = 0; i < 8; i++) {
		thv = pthread_join(thr[i], NULL);
		
		if (thv != 0) {
			fprintf(stderr, "Cannot join thread %d\n", i);
		
			exit(EXIT_FAILURE);
		}
		
		printf("Thread %i finished\n", i);
		
		sum += w[i].sum;
	}

	printf("Sum is %lu\n", sum);

	unmap_file_region(&region);
	
	free(w);
	w = NULL;

	return EXIT_SUCCESS;
}