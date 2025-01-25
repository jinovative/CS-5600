/*
 * queue.c / Asignment_3_Part_2_Program Execution and Process Queue
 *
 * JinYoung Park / CS5600 / Northeastern University
 * Spring 2025 / Jan 22, 2025
 *
 */




#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// create queue
queue_t* create_queue() {
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

// add data in queue
void push_queue(queue_t *queue, void *element) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = element;
    new_node->next = NULL;
    new_node->prev = queue->tail;

    if (queue->tail) {
        queue->tail->next = new_node;
    } else {
        queue->head = new_node;
    }
    queue->tail = new_node;
    queue->size++;
}

// delet data in queue
void* pop_queue(queue_t *queue) {
    if (!queue->head) return NULL;

    node_t *temp = queue->head;
    void *data = temp->data;
    queue->head = temp->next;

    if (queue->head) {
        queue->head->prev = NULL;
    } else {
        queue->tail = NULL;
    }

    free(temp);
    queue->size--;
    return data;
}

// delet process of highest priority
process_t* remove_process(queue_t *queue) {
    if (!queue->head) return NULL;

    node_t *current = queue->head;
    node_t *highest = current;
    process_t *highest_process = (process_t *)current->data;

    while (current) {
        process_t *current_process = (process_t *)current->data;
        if (current_process->priority > highest_process->priority) {
            highest = current;
            highest_process = current_process;
        }
        current = current->next;
    }

    if (highest->prev) {
        highest->prev->next = highest->next;
    } else {
        queue->head = highest->next;
    }

    if (highest->next) {
        highest->next->prev = highest->prev;
    } else {
        queue->tail = highest->prev;
    }

    free(highest);
    queue->size--;
    return highest_process;
}

// return size of queue
int get_queue_size(queue_t *queue) {
    return queue->size;
}

// free memory queue
void free_queue(queue_t *queue) {
    while (queue->head) {
        pop_queue(queue);
    }
    free(queue);
}

