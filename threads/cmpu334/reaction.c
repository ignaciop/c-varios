#include <stdio.h>
#include <stdlib.h>
#include "reaction.h"

void reaction_init(struct reaction *reaction) {
	reaction->oxygen_count = 0;
	reaction->hydrogen_count = 0;
	
	int mt = pthread_mutex_init(&reaction->lock, NULL);
	
	if (mt != 0) {
		perror("Error initializing mutex: ");
		
		exit(EXIT_FAILURE);
	}
	
	int cv = pthread_cond_init(&reaction->oxygen_cond, NULL);
	
	if (cv != 0) {
		perror("Error initializing condition variable: ");
		
		exit(EXIT_FAILURE);
	}
	
	int cv2 = pthread_cond_init(&reaction->hydrogen_cond, NULL);
	
	if (cv2 != 0) {
		perror("Error initializing condition variable: ");
		
		exit(EXIT_FAILURE);
	}
}

void reaction_h(struct reaction *reaction) {
	int ml = pthread_mutex_lock(&reaction->lock);
	
	if (ml != 0) {
		perror("Error locking mutex: ");
		
		exit(EXIT_FAILURE);
	}
	
	if (reaction->oxygen_count > 0 && reaction->hydrogen_count > 0) {
		reaction->hydrogen_count--;
		reaction->oxygen_count--;
		
		int cs = pthread_cond_signal(&reaction->hydrogen_cond);
		
		if (cs != 0) {
			perror("Error signaling condition variable: ");
		
			exit(EXIT_FAILURE);
		}
		
		cs = pthread_cond_signal(&reaction->oxygen_cond);
		
		if (cs != 0) {
			perror("Error signaling condition variable: ");
		
			exit(EXIT_FAILURE);
		}
		
		make_water();
	} else {
		reaction->hydrogen_count++;
		
		int cw = pthread_cond_wait(&reaction->hydrogen_cond, &reaction->lock);
		
		if (cw != 0) {
			perror("Error waiting condition variable: ");
		
			exit(EXIT_FAILURE);
		}
	}
	
	ml = pthread_mutex_unlock(&reaction->lock);
	
	if (ml != 0) {
		perror("Error unlocking mutex: ");
		
		exit(EXIT_FAILURE);
	}
}

void reaction_o(struct reaction *reaction) {
	int ml = pthread_mutex_lock(&reaction->lock);
	
	if (ml != 0) {
		perror("Error locking mutex: ");
		
		exit(EXIT_FAILURE);
	}
	
	if (reaction->hydrogen_count > 1) {
		reaction->hydrogen_count -= 2;
		
		int cs = pthread_cond_signal(&reaction->hydrogen_cond);
		
		if (cs != 0) {
			perror("Error signaling condition variable: ");
		
			exit(EXIT_FAILURE);
		}
		
		cs = pthread_cond_signal(&reaction->hydrogen_cond);
		
		if (cs != 0) {
			perror("Error signaling condition variable: ");
		
			exit(EXIT_FAILURE);
		}
		
		make_water();
	} else {
		reaction->oxygen_count++;
		
		int cw = pthread_cond_wait(&reaction->oxygen_cond, &reaction->lock);
		
		if (cw != 0) {
			perror("Error waiting condition variable: ");
		
			exit(EXIT_FAILURE);
		}
	}
	
	ml = pthread_mutex_unlock(&reaction->lock);
	
	if (ml != 0) {
		perror("Error unlocking mutex: ");
		
		exit(EXIT_FAILURE);
	}
}