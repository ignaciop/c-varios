#include <stdio.h>
#include <stdlib.h>

#include "disease_model.h"

int main(int argv, char* argc[]) {
	/* Read the files in and store them */
	struct graph *tiny_pop = read_file("tiny_population.txt");
	struct graph *small_pop = read_file("small_population.txt");
	struct graph *medium_pop = read_file("medium_population.txt");
	struct graph *large_pop = read_file("large_population.txt");
	struct graph *huge_pop = read_file("huge_population.txt");

	/* Part Two: seeding! */
	printf("%s\n", "Part Two: Seeding!");
	seed_graph(&tiny_pop, 0);
	print_graph(tiny_pop);
	print_stats(tiny_pop);
	
	/* Seeding the same person twice has no effect */
	seed_graph(&tiny_pop, 0); 
	print_graph(tiny_pop);
	print_stats(tiny_pop);

	seed_graph(&small_pop, 5);
	seed_graph(&small_pop, 7);
	print_graph(small_pop);
	print_stats(small_pop);

	seed_graph(&medium_pop, 10000); /* will fail, set it up so it won't segfault */
	print_stats(medium_pop);
	seed_graph(&medium_pop, 11);

	/* Large and huge will be seeded, too */
	seed_graph(&large_pop, 0);
	seed_graph(&huge_pop, (huge_pop->n) - 1);

	printf("\n");

	/* Part Three: Propagate Once */
	printf("\n\n%s\n", "Part Three: Propagate Once");
	propagate_once(&tiny_pop, 1);
	print_graph(tiny_pop);
	print_stats(tiny_pop);
	propagate_once(&tiny_pop, 1);
	print_graph(tiny_pop);
	print_stats(tiny_pop);

	printf("\n%s\n", "And let's check the huge one:");
	propagate_once(&huge_pop, 1);
	print_stats(huge_pop);
	propagate_once(&huge_pop, 1);
	print_stats(huge_pop);
	propagate_once(&huge_pop, 1);
	print_stats(huge_pop);

	/* Part Four: Propagate N Times */
	printf("\n\n%s\n", "Part Four: Propagate N Times");
	propagate_n_times(&small_pop, 2, 1);
	print_graph(small_pop);

	printf("%s\n", "And back to huge:");
	propagate_n_times(&huge_pop, 10, 1);

	/* Part Five: Propagate with probability */
	srand(190); /* seed on 190 */
	printf("%s\n", "And now we propagate with probability");
	propagate_n_times(&large_pop, 10, 0.8);

	printf("%s\n", "Trying on medium:");
	propagate_n_times(&medium_pop, 4, 0); /* should not infect */
	printf("\n");
	propagate_n_times(&medium_pop, 10, 0.5); /* should infect slowly */

	remove_all(&tiny_pop);
	remove_all(&small_pop);
	remove_all(&medium_pop);
	remove_all(&large_pop);
	remove_all(&huge_pop);
	
	return EXIT_SUCCESS;
}

/* Output is in test_infections.txt */