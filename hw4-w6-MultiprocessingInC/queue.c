/*
 * queue.c / Asignment_4 Week6 MultiprocessingInC
 *
 * JinYoung Park / CS5600 / Northeastern University
 * Spring 2025 / Feb 5, 2025
 *
 */



#include "queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Queue* create_queue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void enqueue(Queue *queue, const char *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = strdup(data);
    new_node->next = NULL;
    if (queue->rear) {
        queue->rear->next = new_node;
    }
    queue->rear = new_node;
    if (!queue->front) {
        queue->front = new_node;
    }
    queue->size++;
}

char* dequeue(Queue *queue) {
    if (!queue->front) return NULL;
    Node *temp = queue->front;
    char *data = strdup(temp->data);
    queue->front = queue->front->next;
    if (!queue->front) queue->rear = NULL;
    free(temp->data);
    free(temp);
    queue->size--;
    return data;
}

void free_queue(Queue *queue) {
    while (queue->front) {
        free(dequeue(queue));
    }
    free(queue);
}

