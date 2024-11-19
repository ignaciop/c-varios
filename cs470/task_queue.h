#ifndef TASK_QUEUE_H
#define TASK_QUEUE_H

struct task {
    char action;
    int num;
    struct task *next;
};

struct task_queue {
    struct task *head;
    struct task *tail;
    size_t size;
};

struct task_queue *task_queue_create(void);
void task_queue_enqueue(struct task_queue *q, char action, int num);
struct task *task_queue_dequeue(struct task_queue *q);
void task_queue_print(struct task_queue *q);
size_t task_queue_size(struct task_queue *q);
void task_queue_destroy(struct task_queue **q);

#endif