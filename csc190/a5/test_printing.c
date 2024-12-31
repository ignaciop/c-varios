#include <stdio.h>
#include <stdlib.h>

#include "disease_model.h"

int main(int argv, char* argc[]) {
	/* Part One: reading in the files */

	printf("%s\n", "Printing tiny_pop:");
	struct graph *tiny_pop = read_file("tiny_population.txt");
	print_graph(tiny_pop);
	print_stats(tiny_pop);
    
	printf("\n%s\n", "Printing small_pop:"); 
	struct graph *small_pop = read_file("small_population.txt");
	print_graph(small_pop);
	print_stats(small_pop);

	printf("\n%s\n", "Printing medium_pop:"); 
	struct graph *medium_pop = read_file("medium_population.txt");
	print_graph(medium_pop);
	print_stats(medium_pop);

	printf("\n%s\n", "Stats for large_pop:"); 
	struct graph *large_pop = read_file("large_population.txt");
	print_stats(large_pop);

	printf("\n%s\n", "Stats for huge_pop:"); 
	struct graph *huge_pop = read_file("huge_population.txt");
	print_stats(huge_pop);

	remove_all(&tiny_pop);
	remove_all(&small_pop);
	remove_all(&medium_pop);
	remove_all(&large_pop);
	remove_all(&huge_pop);
	
	return EXIT_SUCCESS;
}

/* Expected output:
[patitsas@localhost solution]$ make printing
[patitsas@localhost solution]$ ./printing
Printing tiny_pop:
 	0,1,2,3 	status
0	0,0,1,1 	S
1	0,0,1,1 	S
2	1,1,0,1 	S
3	1,1,1,0 	S
===============
STATS: S 100%, I   0%, V   0%, n =   4
===============

Printing small_pop:
 	0,1,2,3,4,5,6,7 	status
0	0,1,1,0,0,0,0,0 	S
1	1,0,0,1,0,0,0,1 	S
2	1,0,0,0,1,0,0,0 	S
3	0,1,0,0,0,0,0,0 	S
4	0,0,1,0,0,1,0,0 	S
5	0,0,0,0,1,0,0,0 	S
6	0,0,0,0,0,0,0,1 	S
7	0,1,0,0,0,0,1,0 	S
===============
STATS: S 100%, I   0%, V   0%, n =   8
===============

Printing medium_pop:
 	0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 	status
0	0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0 	S
1	1,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0 	S
2	0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0 	S
3	1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0 	S
4	1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0 	S
5	0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 	S
6	0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0 	S
7	0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0 	S
8	0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0 	S
9	0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0 	S
10	0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0 	S
11	0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0 	S
12	0,0,0,1,0,0,1,1,0,1,0,0,0,0,0,1 	S
13	0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 	S
14	0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1 	S
15	0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0 	S
===============
STATS: S 100%, I   0%, V   0%, n =  16
===============

Stats for large_pop:
STATS: S 100%, I   0%, V   0%, n =  64

Stats for huge_pop:
STATS: S 100%, I   0%, V   0%, n = 512

[patitsas@localhost solution]$ 
*/
