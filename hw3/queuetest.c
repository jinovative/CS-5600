/*
 * queuetest.c / Asignment_3_Part_2_Program Execution and Process Queue
 *
 * JinYoung Park / CS5600 / Northeastern University
 * Spring 2025 / Jan 22, 2025
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// function to print queue 
void print_queue(queue_t *queue) {
    if (queue->size == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue :\n");
    node_t *current = queue->head;
    while (current) {
        process_t *process = (process_t *)current->data;
        printf("Process ID: %d, Name: %s, Runtime: %ld, Priority: %d\n",
               process->id, process->name, process->runtime, process->priority);
        current = current->next;
    }
}

int main() {
    printf("Queue created.\n");
    queue_t *queue = create_queue();

    // Initial queue state
    printf("Queue size: %d\n\n", get_queue_size(queue));

    // Create processes
    process_t *p1 = (process_t *)malloc(sizeof(process_t));
    p1->id = 1; p1->name = "Process 1"; p1->runtime = 20; p1->priority = 2;

    process_t *p2 = (process_t *)malloc(sizeof(process_t));
    p2->id = 2; p2->name = "Process 2"; p2->runtime = 60; p2->priority = 5;

    process_t *p3 = (process_t *)malloc(sizeof(process_t));
    p3->id = 3; p3->name = "Process 3"; p3->runtime = 45; p3->priority = 3;

    // Add processes to the queue
    printf("Adding Process 1 to the queue.\n");
    push_queue(queue, p1);
    printf("Adding Process 2 to the queue.\n");
    push_queue(queue, p2);
    printf("Adding Process 3 to the queue.\n");
    push_queue(queue, p3);

    // Print updated queue state
    printf("Queue size: %d\n", get_queue_size(queue));
    print_queue(queue);
    printf("\n");

    // Pop the first process from the queue
    process_t *popped = (process_t *)pop_queue(queue);
    printf("Popping process from the queue: %s\n", popped->name);
    free(popped);

    // Print updated queue state
    printf("Queue size: %d\n", get_queue_size(queue));
    print_queue(queue);
    printf("\n");

    // Remove the highest-priority process
    process_t *highest = remove_process(queue);
    printf("Removing highest priority process: %s\n", highest->name);
    free(highest);

    // Print final queue state
    printf("Queue size: %d\n", get_queue_size(queue));
    print_queue(queue);
    printf("\n");

    // Free the queue
    printf("Freeing the queue.\n");
    free_queue(queue);
    printf("All processes removed, memory released.\n");

    return 0;
}

