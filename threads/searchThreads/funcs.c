/*
 * Auxiliary functions to support a program to exemplify 
 * the use of the PThread library.
 *
 * Author: Andre Leon S. Gradvohl, Dr.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "funcs.h"

#define FALSE 0
#define TRUE  1

/*
 * Checks if an element already exists in an array (disordered).
 * The search starts at position zero.
 * @param element Element to be searched in the array.
 * @param array Array where the element is searched.
 * @param size Array size.
 *
 * @return FALSE (0) if the element does not exist in the array.
 *         TRUE otherwise.
 */
short exists(int element, int *array, int size) {
	if (size > 0) {
		for (register int i = 0; i < size; i++) {
	  		if (array[i] == element) {
				return TRUE;
	  		}
		}
	}
	
	return FALSE;
}

/*
 * Creates an array of random integers with a specific size.
 * @param size Array size.
 *
 * @return The address of the allocated array.
 */
int *createRandomArray(unsigned int size) {
	int element;
	int *array = (int *)malloc(sizeof(int) * size);

	if (array == NULL) {
		fprintf(stderr, "There is an Error in the array memory allocation.\n");
		
		exit(EXIT_FAILURE);
	}
	
	srand(time(NULL));

	for (register unsigned int i = 0; i < size; i++) {
		do {
	  		element = rand() % (size + 1);
		} while (exists(element, array, i));

		array[i] = element;
	}

	return array;
}

/*
 * Print the array in the screen.
 * @param array Array to be printed in the screen.
 * @param size Array size.
 */
void printArray(int *array, unsigned int size) {
	fprintf(stdout, "Array: [");
	
	for (register unsigned int i = 0; i < size - 1; i++) {
		fprintf(stdout, "%d, ", array[i]);
	}

	fprintf(stdout, "%d]\n", array[size - 1]);
}

/*
 * Allocates an array of thread identifiers in memory.
 *
 * @param size Size of the array.
 *
 * @return Memory address of the array.
 */
pthread_t *threadIDsAllocation(unsigned int size) {
	pthread_t *threadsIDs = NULL;

	if (size > 0) {
		threadsIDs = (pthread_t *)malloc(sizeof(pthread_t) * size);
		
		if (threadsIDs == NULL) {
	  		fprintf(stderr, "Problems on allocating threads ids array in memory\n");
		
			exit(EXIT_FAILURE);
		}
	}

	return threadsIDs;
}