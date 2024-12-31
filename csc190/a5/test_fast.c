#include <stdio.h>
#include <stdlib.h>

#include "disease_model.h"

int main(int argv, char* argc[]) {
	struct graph *huge_pop = read_file("huge_population.txt");

	/*
	 * Before we call any random numbers	
	 * let's all use a common seed
	 */
	srand(190);
 
	/* Start an infection */
	seed_graph(&huge_pop, 0);
 
	/* And propagate 1000 times */
	propagate_n_times(&huge_pop, 10000, 0.001);

	remove_all(&huge_pop);

	return EXIT_SUCCESS;
}

/*
[patitsas@remote a5]$ make slow
[patitsas@remote a5]$ ./slow > slow_output.txt
[patitsas@remote a5]$ gprof slow > slow_profile.txt
[patitsas@remote a5]$ make fast
[patitsas@remote a5]$ ./fast > fast_output.txt
[patitsas@remote a5]$ gprof fast > fast_profile.txt 
[patitsas@remote a5]$ diff slow_output.txt fast_output.txt 
*/