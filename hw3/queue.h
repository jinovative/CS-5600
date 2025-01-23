/*
 * queue.h / Asignment_3_Part_2_Program Execution and Process Queue
 *
 * JinYoung Park / CS5600 / Northeastern University
 * Spring 2025 / Jan 22, 2025
 *
 */



#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

// process structure
typedef struct {
    int id;
    char *name;
    long runtime;
    int priority;
} process_t;

// node structure
typedef struct node {
    void *data;
    struct node *next;
    struct node *prev;
} node_t;

// queue structure
typedef struct {
    node_t *head;
    node_t *tail;
    int size;
} queue_t;

// prototype of function
queue_t* create_queue();
void push_queue(queue_t *queue, void *element);
void* pop_queue(queue_t *queue);
process_t* remove_process(queue_t *queue);
int get_queue_size(queue_t *queue);
void free_queue(queue_t *queue);

#endif

