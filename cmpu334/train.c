#include <stdio.h>
#include <stdlib.h>
#include "train.h"

void station_init(struct station *station) {
	station->waiting_train_passengers = 0;
	station->on_board_passengers = 0;
	
	int mt = pthread_mutex_init(&station->train_lock, NULL);
	
	if (mt != 0) {
		perror("Error initializing mutex: ");
		
		exit(EXIT_FAILURE);
	}
	
	int cv = pthread_cond_init(&station->arrive_of_train, NULL);
	
	if (cv != 0) {
		perror("Error initializing condition variable: ");
		
		exit(EXIT_FAILURE);
	}
	
	int cv2 = pthread_cond_init(&station->all_passengers_on_board, NULL);
	
	if (cv2 != 0) {
		perror("Error initializing condition variable: ");
		
		exit(EXIT_FAILURE);
	}
}

void station_load_train(struct station *station, int count) {
	int ml = pthread_mutex_lock(&station->train_lock);
	
	if (ml != 0) {
		perror("Error obtaining mutex lock: ");
		
		exit(EXIT_FAILURE);
	}
	
	station->empty_seat_train = count;
	
	while (station->empty_seat_train > 0 && station->waiting_train_passengers > 0) {
		int cv = pthread_cond_broadcast(&station->arrive_of_train);
		
		if (cv != 0) {
			perror("Error broadcasting condition variable: ");
		
			exit(EXIT_FAILURE);
		}
		
		cv = pthread_cond_wait(&station->all_passengers_on_board, &station->train_lock);
		
		if (cv != 0) {
			perror("Error wating condition variable: ");
		
			exit(EXIT_FAILURE);
		}
	}
	
	station->empty_seat_train = 0;
	
	ml = pthread_mutex_unlock(&station->train_lock);
	
	if (ml != 0) {
		perror("Error obtaining mutex unlock: ");
		
		exit(EXIT_FAILURE);
	}
}

void station_wait_for_train(struct station *station) {
	int ml = pthread_mutex_lock(&station->train_lock);
	
	if (ml != 0) {
		perror("Error obtaining mutex lock: ");
		
		exit(EXIT_FAILURE);
	}
	
	station->waiting_train_passengers++;
	
	while (station->on_board_passengers == station->empty_seat_train) {
		int cv = pthread_cond_wait(&station->arrive_of_train, &station->train_lock);
	
		if (cv != 0) {
			perror("Error waiting condition variable: ");
		
			exit(EXIT_FAILURE);
		}
	}
	
	station->on_board_passengers++;
	station->waiting_train_passengers--;
	
	ml = pthread_mutex_unlock(&station->train_lock);
	
	if (ml != 0) {
		perror("Error obtaining mutex unlock: ");
		
		exit(EXIT_FAILURE);
	}
}

void station_on_board(struct station *station) {
	int ml = pthread_mutex_lock(&station->train_lock);
	
	if (ml != 0) {
		perror("Error obtaining mutex lock: ");
		
		exit(EXIT_FAILURE);
	}
	
	station->on_board_passengers--;
	station->empty_seat_train--;
	
	if (station->empty_seat_train == 0 || (station->on_board_passengers == 0 &&
		station->waiting_train_passengers == 0)) {
		int cs = pthread_cond_signal(&station->all_passengers_on_board);
	
		if (cs != 0) {
			perror("Error signaling condition variable: ");
		
			exit(EXIT_FAILURE);
		}	
	}
	
	ml = pthread_mutex_unlock(&station->train_lock);
	
	if (ml != 0) {
		perror("Error obtaining mutex unlock: ");
		
		exit(EXIT_FAILURE);
	}
}