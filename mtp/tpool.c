#include <stdio.h>
#include <stdlib.h>

#include "tpool.h"

/* Simple helpers for creating and destroying work objects. */

static tpool_work_t *tpool_work_create(thread_func_t func, void *arg) {
    if (func == NULL) {
        return NULL;
    }
    
    tpool_work_t *work = (tpool_work_t *)malloc(sizeof(tpool_work_t));
    
    if (work == NULL) {
        perror("Error allocating memory for new work");
        
        exit(EXIT_FAILURE);
    }
    
    work->func = func;
    work->arg = arg;
    work->next = NULL;
    
    return work;
}

static void tpool_work_destroy(tpool_work_t *work) {
    if (work != NULL) {
        free(work);
        work = NULL;
    }
}

static tpool_work_t *tpool_work_get(tpool_t *tm) {
    if (tm == NULL) {
        return NULL;
    }
    
    tpool_work_t *work = tm->work_first;
    
    if (work == NULL) {
        return NULL;
    }
    
    if (work->next == NULL) {
        tm->work_first = tm->work_last = NULL;
    } else {
        tm->work_first = work->next;
    }
    
    return work;
}

static void *tpool_worker(void *arg) {
    tpool_t *tm = arg;
    tpool_work_t *work = NULL;
    
    int mt = 0;
    int cv = 0;
    
    while (1) {
        mt = pthread_mutex_lock(&(tm->work_mutex));
        
        if (mt != 0) {
            perror("Error locking mutex");
        
            exit(EXIT_FAILURE);
        }
        
        while (tm->work_first == NULL && !tm->stop) {
            cv = pthread_cond_wait(&(tm->work_cond), &(tm->work_mutex));
            
            if (cv != 0) {
                perror("Error waiting for condition variable");
        
                exit(EXIT_FAILURE);
            }
        }
        
        if (tm->stop) {
            break;
        }
        
        work = tpool_work_get(tm);
        tm->working_cnt++;
        
        mt = pthread_mutex_unlock(&(tm->work_mutex));
        
        if (mt != 0) {
            perror("Error unlocking mutex");
        
            exit(EXIT_FAILURE);
        }
        
        if (work != NULL) {
            work->func(work->arg);
            
            tpool_work_destroy(work);
        }
        
        mt = pthread_mutex_lock(&(tm->work_mutex));
        
        if (mt != 0) {
            perror("Error locking mutex");
        
            exit(EXIT_FAILURE);
        }
        
        tm->working_cnt--;
        
        if (!tm->stop && tm->working_cnt == 0 && tm->work_first == NULL) {
            cv = pthread_cond_signal(&(tm->working_cond));
            
            if (cv != 0) {
                perror("Error signaling condition variable");
        
                exit(EXIT_FAILURE);
            }
        }
        
        mt = pthread_mutex_unlock(&(tm->work_mutex));
        
        if (mt != 0) {
            perror("Error unlocking mutex");
        
            exit(EXIT_FAILURE);
        }
    }
    
    tm->thread_cnt--;
    
    cv = pthread_cond_signal(&(tm->working_cond));
    
    if (cv != 0) {
        perror("Error signaling condition variable");
        
        exit(EXIT_FAILURE);
    }
    
    mt = pthread_mutex_unlock(&(tm->work_mutex));
    
    if (mt != 0) {
        perror("Error unlocking mutex");
        
        exit(EXIT_FAILURE);
    }
    
    return NULL; 
}

tpool_t *tpool_create(size_t num) {
    pthread_t thread = 0;
    int mti = 0;
    int cvi = 0;
    int pc = 0;
    
    tpool_t *tm = (tpool_t *)calloc(1, sizeof(tpool_t));
    
    if (tm == NULL) {
        perror("Error allocating memory for new pool");
        
        exit(EXIT_FAILURE);
    }
    
    if (num == 0) {
        num = 2;
    }
    
    tm->thread_cnt = num;
    
    mti = pthread_mutex_init(&(tm->work_mutex), NULL);
    
    if (mti != 0) {
        perror("Error initializing mutex");
        
        exit(EXIT_FAILURE);
    }
    
    cvi = pthread_cond_init(&(tm->work_cond), NULL);
    
    if (cvi != 0) {
        perror("Error initializing condition variable");
        
        exit(EXIT_FAILURE);
    }
    
    cvi = pthread_cond_init(&(tm->working_cond), NULL);
    
    if (cvi != 0) {
        perror("Error initializing condition variable");
        
        exit(EXIT_FAILURE);
    }
    
    tm->work_first = tm->work_last = NULL;
    
    for (int i = 0; i < num; i++) {
        pc = pthread_create(&thread, NULL, tpool_worker, tm);
        
        if (pc != 0) {
            perror("Error creating thread");
        
            exit(EXIT_FAILURE);
        }
        
        pc = pthread_detach(thread);
        
        if (pc != 0) {
            perror("Error detaching thread");
        
            exit(EXIT_FAILURE);
        }
    }
    
    return tm;
}

void tpool_destroy(tpool_t *tm) {
    if (tm == NULL) {
        return;
    }
    
    int mt = 0;
    int cv = 0;
    
    mt = pthread_mutex_lock(&(tm->work_mutex));
    
    if (mt != 0) {
        perror("Error locking mutex");
        
        exit(EXIT_FAILURE);
    }
        
    tpool_work_t *work = tm->work_first;
    
    while (work != NULL) {
        tpool_work_t *work2 = work->next;
        
        tpool_work_destroy(work);
        
        work = work2;
    }
    
    tm->work_first = NULL;
    tm->stop = true;
    
    cv = pthread_cond_broadcast(&(tm->work_cond));
    
    if (cv != 0) {
        perror("Error broadcasting condition variable");
        
        exit(EXIT_FAILURE);
    }
        
    mt = pthread_mutex_unlock(&(tm->work_mutex));
    
    if (mt != 0) {
        perror("Error unlocking mutex");
        
        exit(EXIT_FAILURE);
    }
        
    tpool_wait(tm);
    
    mt = pthread_mutex_destroy(&(tm->work_mutex));
    
    if (mt != 0) {
        perror("Error destroying mutex");
        
        exit(EXIT_FAILURE);
    }
    
    cv = pthread_cond_destroy(&(tm->work_cond));
    
    if (cv != 0) {
        perror("Error destroying condition variable");
        
        exit(EXIT_FAILURE);
    }
    
    cv = pthread_cond_destroy(&(tm->working_cond));
    
    if (cv != 0) {
        perror("Error destroying condition variable");
        
        exit(EXIT_FAILURE);
    }
    
    free(tm);
    tm = NULL;
}

bool tpool_add_work(tpool_t *tm, thread_func_t func, void *arg) {
    if (tm == NULL) {
        return false;
    }
    
    tpool_work_t *work = tpool_work_create(func, arg);
    
    if (work == NULL) {
        return false;
    }
    
    int mt = 0;
    int cv = 0;
    
    mt = pthread_mutex_lock(&(tm->work_mutex));
    
    if (mt != 0) {
        perror("Error locking mutex");
        
        exit(EXIT_FAILURE);
    }
    
    if (tm->work_first == NULL) {
        tm->work_first = work;
        tm->work_last = tm->work_first;
    } else {
        tm->work_last->next = work;
        tm->work_last = work;
    }
    
    cv = pthread_cond_broadcast(&(tm->work_cond));
    
    if (cv != 0) {
        perror("Error broadcasting condition variable");
        
        exit(EXIT_FAILURE);
    }
    
    mt = pthread_mutex_unlock(&(tm->work_mutex));
    
    if (mt != 0) {
        perror("Error unlocking mutex");
        
        exit(EXIT_FAILURE);
    }
    
    return true;
}

void tpool_wait(tpool_t *tm) {
    if (tm == NULL) {
        return;
    }

    int mt = 0;
    int cv = 0;
    
    mt = pthread_mutex_lock(&(tm->work_mutex));
    
    if (mt != 0) {
        perror("Error locking mutex");
        
        exit(EXIT_FAILURE);
    }
    
    while (1) {
        if (tm->work_first != NULL || (!tm->stop && tm->working_cnt != 0) || (tm->stop && tm->thread_cnt != 0)) {
            cv = pthread_cond_wait(&(tm->working_cond), &(tm->work_mutex));
            
            if (cv != 0) {
                perror("Error waiting condition variable");
        
                exit(EXIT_FAILURE);
            }
        } else {
            break;
        }
    }
    
    mt = pthread_mutex_unlock(&(tm->work_mutex));
    
    if (mt != 0) {
        perror("Error unlocking mutex");
        
        exit(EXIT_FAILURE);
    }
}