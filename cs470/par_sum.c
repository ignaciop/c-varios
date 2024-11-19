/*
 * par_sum.c
 *
 * CS 470 Project 1 (Pthreads)
 * Parallel version
 *
 */

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "task_queue.h"

struct task_queue *tq;

// aggregate variables
int sum = 0;
int odd = 0;
int min = INT_MAX;
int max = INT_MIN;
bool done = false;

char *fn;

char action;
int num;

pthread_mutex_t tq_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t vars_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t tq_wait = PTHREAD_COND_INITIALIZER;

// function prototypes
void *worker_thread(void *arg);
void *supervisor_thread(void *arg);

void *worker_thread(void *arg) {
    while (1) {
        pthread_mutex_lock(&tq_lock);

        while (task_queue_size(tq) == 0 && !done) {
            pthread_cond_wait(&tq_wait, &tq_lock);
        }
        
        if (done && task_queue_size(tq) == 0) {
            pthread_mutex_unlock(&tq_lock);
            
            break; // No more tasks to process
        }
        
        struct task *pt = task_queue_dequeue(tq);

        pthread_mutex_unlock(&tq_lock);  

        pthread_mutex_lock(&vars_lock);  
    
        // update aggregate variables
        sum += pt->num;

        if (pt->num % 2 == 1) {
            odd++;
        }

        if (pt->num < min) {
            min = pt->num;
        }

        if (pt->num > max) {
            max = pt->num;
        }
        
        free(pt);
        pt = NULL;

        pthread_mutex_unlock(&vars_lock);
    }

    return NULL;
}

void *supervisor_thread(void *arg) {
    // open input file
    FILE *fin = fopen(fn, "r");
    
    if (fin == NULL) {
        printf("ERROR: Could not open %s\n", fn);
        
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(fin, "%c %d\n", &action, &num) == 2) {
        // check for invalid action parameters
        if (num < 1) {
            printf("ERROR: Invalid action parameter: %d\n", num);
            
            fclose(fin);
            
            exit(EXIT_FAILURE);
        }

        if (action == 'p') {            // process
            pthread_mutex_lock(&tq_lock);
            
            task_queue_enqueue(tq, action, num);

            done = false;

            pthread_cond_signal(&tq_wait);
            
            pthread_mutex_unlock(&tq_lock);
        } else if (action == 'w') {     // wait
            sleep(num);
        } 
    }

    pthread_mutex_lock(&tq_lock);
    done = true;  // Set the done flag to true when quitting
            
    // Wake up all worker threads to exit
    pthread_cond_broadcast(&tq_wait);
    pthread_mutex_unlock(&tq_lock);
    
    fclose(fin);

    return NULL;
}

int main(int argc, char *argv[]) {
    // check and parse command line options
    if (argc != 3) {
        printf("%s\n", "Usage: sum <infile> <worker_threads>");
        
        exit(EXIT_FAILURE);
    }
    
    fn = argv[1];
    int worker_threads = atoi(argv[2]);
    
    if (worker_threads <= 0) {
        printf("%s\n", "The number of worker threads must be greater than zero.");
        
        exit(EXIT_FAILURE);
    }
    
    pthread_t supervisor = 0;
    pthread_t *workers = (pthread_t *)malloc(sizeof(pthread_t) * worker_threads);
    
    if (workers == NULL) {
        perror("Cannot allocate memory for new threads id array.\n");
        
        exit(EXIT_FAILURE);
    }
    
    tq = task_queue_create();
    
    pthread_create(&supervisor, NULL, supervisor_thread, NULL);
    
    for (int i = 0; i < worker_threads; i++) {
        pthread_create(&workers[i], NULL, worker_thread, NULL);
    }
    
    for (int i = 0; i < worker_threads; i++) {
        pthread_join(workers[i], NULL);
    }
    
    pthread_join(supervisor, NULL);

    free(workers);
    workers = NULL;

    task_queue_destroy(&tq);
    
    // print results
    printf("%d %d %d %d\n", sum, odd, min, max);

    // clean up and return
    return EXIT_SUCCESS;
}