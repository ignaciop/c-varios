// station.c -- simulates a doubly-linked list of TTC stations
// Ignacio Poggi, 2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ttc.h"

struct station* make_station(char *name, int pos) {
	// Creates a new station node in our doubly-linked list, setting its name and position to name and pos.
	// The new node is unlinked (prev and next are both NULL).
	// PRE: none
	// POST: none

	struct station *new_node = (struct station*)malloc(sizeof(struct station));
	
	if (new_node == NULL) {
		fprintf(stderr, "Cannot allocate memory for new station.\n");
		
		exit(EXIT_FAILURE);
	}
	
	new_node->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
	
	if (new_node->name == NULL) {
		fprintf(stderr, "Cannot allocate memory for new station name.\n");
		
		exit(EXIT_FAILURE);
	}
	
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

	if (curr_station != NULL && curr_station->passengers != NULL) {
		return num_passengers(curr_station->passengers);
	}

	return 0;
}

void print_station(struct station *current) {
	// Prints a single station. If current == NULL, prints "No station. \n".
	// PRE: none.
	// POST: none
	if (current == NULL) {
		printf("%s\n", "No station. ");
	} else {
		if (current->prev != NULL) {
			printf("%13s -> ", current->prev->name);
		} else {
			printf("%s", "                 ");
		}

		printf("%s (%d)", current->name, num_passengers(current->passengers));
		
		if (current->next != NULL) {
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

	printf("\n%s\n", "The stations: ");
	
	struct station *curr_station = first;
	
	while (curr_station != NULL) {
		print_station(curr_station);
		
		curr_station = curr_station->next;
	}
}

// The functions beneath this line are for students to implement.

void insert_station_after(struct station *node, struct station *new_node) {
	new_node->prev = node;
	new_node->next = node->next;
	
	if (node->next != NULL) {
        node->next->prev = new_node;
    }
    
	node->next = new_node;
}

struct station* read_stations() {
	// Make head station
	//  save this station as prev_station
	// while reading file
	// 	make new station
	//	insert_station_after(prev_station, new)
	//  prev_station = new_station
	FILE *station_file = fopen("bloor_line.txt", "r");
	
	if (station_file == NULL) {
		fprintf(stderr, "Cannot read input file.\n");
		
		exit(EXIT_FAILURE);
	}
	
	char *first_st_name;
	int first_st_pos;
	
	fscanf(station_file, "%s %d", first_st_name, &first_st_pos);
	
	struct station *first_station = make_station(first_st_name, first_st_pos);
	struct station *prev_station = first_station;
	
	while (!feof(station_file)) {
		char *station_name;
		int station_pos;
		
		fscanf(station_file, "%s %d", station_name, &station_pos);
		
		struct station *nx_station = make_station(station_name, station_pos);
		
		insert_station_after(prev_station, nx_station);
		
		prev_station = nx_station;
	}
	
	fclose(station_file);
	
	return first_station;
}

void add_passenger(struct station *curr_station) {
 	if (curr_station == NULL) {
		fprintf(stderr, "Cannot add passenger to NULL station.\n");
		
		exit(EXIT_FAILURE);
	}
	
	struct passenger *pax = make_passenger();
	
	if (curr_station->passengers == NULL) {
		curr_station->passengers = pax;
	} else {
		insert_passenger_after(curr_station->passengers, pax);
	}
}

void add_n_passengers(struct station *curr_station, int n) {
	for (int i = 1; i <= n; i++) {
		add_passenger(curr_station);
	}
}

int total_passengers(struct station *first) {
	int total_pax = 0;
	
	struct station *curr_station = first;
	
	while (curr_station != NULL) {
		total_pax += num_passengers(curr_station->passengers);
		
		curr_station = curr_station->next;
	}
	
	return total_pax;
}

double average_wait_time(struct station *first) {
	double avg = 0.0;
	
	int total_wait = 0;
	
	struct station *curr_station = first;
	int total_pax = total_passengers(curr_station);
	
	while (curr_station != NULL) {
		int wait_per_pax = 0;
		
		struct passenger *curr_pax = curr_station->passengers;
		
		while (curr_pax != NULL) {
			wait_per_pax += curr_pax->waiting;
			
			curr_pax = curr_pax->next;
		}
		
		total_wait += wait_per_pax;
		
		curr_station = curr_station->next;
	}
	
	avg = (double)total_wait / total_pax;
	
	return avg;
}

struct station* get_station_at_pos(int position, struct station *first) {
	struct station *ret_station = NULL;
	struct station *curr_station = first;
	
	while (curr_station != NULL) {
		if (curr_station->pos == position) {
			ret_station = curr_station;
			break;
		}
		
		curr_station = curr_station->next;
	}
	
	return ret_station;
}
    
void remove_all_stations(struct station **first) {
	struct station *next_station = (*first)->next;
	
	while (next_station != NULL) {
		struct station *tmp_station = next_station->next;
		
		free(next_station->name);
		next_station->name = NULL;
		
		free(next_station->passengers);
		next_station->passengers = NULL;
		
		free(next_station);
		
		next_station = tmp_station;
	}
	
	free((*first)->name);
	(*first)->name = NULL;
	
	free((*first)->passengers);
	(*first)->passengers = NULL;
	
	free(*first);
	*first = NULL;
}