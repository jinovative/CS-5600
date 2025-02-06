/*
 * main.c / Assignment4 Week6 MultiprossingInC
 *
 * JinYoung Park / CS5600 / Northeastern University
 * Spring 2025 / Feb 5, 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "queue.h"

int main() {
    Queue *queue = create_queue();
    FILE *file = fopen("strings.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        enqueue(queue, buffer);
    }
    fclose(file);

    while (queue->size > 0) {
        FILE *batch_input = fopen("batch_input.txt", "w");
        for (int i = 0; i < 100 && queue->size > 0; i++) {
            char *string = dequeue(queue);
            fprintf(batch_input, "%s\n", string);
            free(string);
        }
        fclose(batch_input);

        if (fork() == 0) {
            execl("./encrypt", "./encrypt", NULL);
            perror("Error launching encrypt process");
            exit(1);
        } else {
            wait(NULL); // Wait for child to finish
        }
    }

    free_queue(queue);
    return 0;
}

