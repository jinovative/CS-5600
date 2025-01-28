#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polybius.h"
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
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline
        enqueue(queue, buffer);
    }
    fclose(file);

    printf("Loaded strings into the queue. Queue size: %d\n", queue->size);
    free_queue(queue);
    return 0;
}

