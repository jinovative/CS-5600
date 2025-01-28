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

