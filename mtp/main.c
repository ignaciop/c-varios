#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include "tpool.h"

static const size_t num_threads = 4;
static const size_t num_items = 100;

void worker(void *arg) {
    int *val = arg;
    int  old = *val;

    *val += 1000;
    
    printf("tid = %p, old = %d, val = %d\n", pthread_self(), old, *val);

    if (*val % 2) {
        usleep(100000);
    }
}

int main(int argc, char **argv) {
    tpool_t *tm = tpool_create(num_threads);
    
    int *vals = calloc(num_items, sizeof(int));
    
    if (vals == NULL) {
        perror("Error allocating memory for new values array");
        
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_items; i++) {
        vals[i] = i;
        tpool_add_work(tm, worker, vals + i);
    }

    tpool_wait(tm);

    for (int i = 0; i < num_items; i++) {
        printf("%d\n", vals[i]);
    }

    free(vals);
    vals = NULL;
    
    tpool_destroy(tm);
    
    return EXIT_SUCCESS;
}