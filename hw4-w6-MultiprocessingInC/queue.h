/*
 * queue.h / Asignment_4 Week6 MultiprocessingInC
 *
 * JinYoung Park / CS5600 / Northeastern University
 * Spring 2025 / Feb 5, 2025
 *
 */

#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue* create_queue();
void enqueue(Queue *queue, const char *data);
char* dequeue(Queue *queue);
void free_queue(Queue *queue);

#endif

