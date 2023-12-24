// station.c -- simulates a doubly-linked list of TTC stations
// YOURNAMESHERE, DATE
#include<stdio.h>
#include<assert.h>
#include "ttc.h"

struct station* make_station(char *name, int pos) {
	// Creates a new station node in our doubly-linked list, setting its name and position to name and pos.
	// The new node is unlinked (prev and next are both NULL).
	// PRE: none
	// POST: none

	struct station *new_node = (struct station*)malloc(sizeof(struct station));
	new_node->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
	strcpy(new_node->name, name);

	new_node->pos = pos;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->passengers = NULL;

	return new_node;
}

int passengers_at_station(struct station *curr_station) {
	// Number of passengers waiting at a given station, curr_station. If station == NULL, returns 0.
	// PRE: none
	// POST: none

	if(curr_station && curr_station->passengers) {
		return num_passengers(curr_station->passengers);
	}

	return 0;
}

void print_station(struct station *current) {
	// Prints a single station. If current == NULL, prints "No station. \n".
	// PRE: none.
	// POST: none
	if(!current) {
		printf("No station. \n");
	} else {
		if(current->prev) {
			printf("%13s -> ", current->prev->name);
		} else {
			printf("                 ");
		}

		printf("%s (%d)", current->name, num_passengers(current->passengers));
		
		if(current->next) {
			printf("-> %-13s \n", current->next->name);
		} else {
			printf("\n");
		}
	}
}

void print_stations(struct station *first) {
	// Prints all stations in a linked list
	// PRE: none
	// POST: none

	printf("\nThe stations: \n");
	
	struct station *curr = first;
	while(curr) {
		print_station(curr);
		curr = curr->next;
	}
}

// The functions beneath this line are for students to implement.

void insert_station_after(struct station *node, struct station *new_node) {

}

struct station* read_stations() {

}

void add_passenger(struct station *curr_station) {

}

void add_n_passengers(struct station *curr_station, int n) {

}

struct station* get_station_at_pos(int position, struct station *first) {

}
    
void remove_all_stations(struct station **first) {

}