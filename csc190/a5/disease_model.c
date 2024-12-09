// your name

#include "disease_model.h"

struct graph* read_file(char* filename)
{
	return NULL;
}

void print_stats(struct graph *pop){}

void print_graph(struct graph *pop){}

void seed_graph(struct graph **pop, int person_id)
{
}

void propagate_once(struct graph **pop){}

void propagate_n_times(struct graph **pop, int n){}

void propagate_with_recovery(struct graph **pop, int n, double p_transmit, int time_to_recover)
{
}


// It's a helper method for lab 10! (You won't need this for lab 9.)
// Elizabeth has adapted this from
// http://stackoverflow.com/questions/6127503/shuffle-array-in-c
void shuffle(int *array, int size)
{
	// shuffles an array of integers in place
	// PRE: none
	// POST: array is shuffled

	if (size > 1) 
	{
		int i;

	        for (i = 0; i < size - 1; i++) 
	        {
			int j = i + rand() / (RAND_MAX / (size - i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
}
