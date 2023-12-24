// passenger.c -- implements a linked list of TTC subway trains
// YOURNAMEHERE, DATE

#include "ttc.h"

struct train* make_train(int iden, int position) {

}

int contains_train_id(struct train *first, int value) {

}

int train_at_position(struct train *first, int pos) {
	// Returns 1 iff there exists a train at position pos (given to students)
	// PRE: none
	// POST: none
	struct train *curr = first;
	int contains_pos = 0;
	
	while(curr) {
		if(curr->pos == pos) {
			return 1;
		}
		
		curr = curr->next;
	}
	
	return contains_pos;
}

void prepend_train(struct train **first, struct train *new_node) {

}

void print_train(struct train *node) {
	// This method is provided to students.
	// Prints a single train, and what it points to (if it points to another train)
	// PRE: node != NULL
	// POST: none
	assert(node);
	printf("Train %d at %d", node->id, node->pos);
	
	if(node->next) {
		printf("; next is %d at %d", node->next->id, node->next->pos);
	}
	
	printf("\n");
}

void print_trains(struct train *first) {

}

int can_advance(struct train *current, int passengers_on_platform) {

}

void advance_train(struct train *current, int passengers_on_platform) {

}

int num_trains(struct train *first) {

}

double avg_train_dist(struct train *first) {

}

void remove_train_after(struct train *node) {

}

void clear_all_trains(struct train **first) {

}