/*
 * multithread.c / Assignment5 / Week7 / Part1
 *
 * JinYoung Park / CS5600 / Northeastern University
 * Spring 2025 / Feb 6, 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define ARRAY_SIZE 10

// Global array shared by all threads.
int shared_data[ARRAY_SIZE];

// Writer thread function: adds different values to each element.
void *writer(void *arg) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        shared_data[i] = (i + 1) * 3; // Different value for each index.
        printf("Writer: shared_data[%d] = %d\n", i, shared_data[i]);
        usleep(100000); // Sleep for 100 milliseconds.
    }
    return NULL;
}

// Reader thread function: reads and prints the global array.
void *reader(void *arg) {
    // Read and print the global array several times.
    for (int j = 0; j < 5; j++) {
        printf("Reader: current shared_data: ");
        for (int i = 0; i < ARRAY_SIZE; i++) {
            printf("%d ", shared_data[i]);
        }
        printf("\n");
        usleep(200000); // Sleep for 200 milliseconds.
    }
    return NULL;
}

int main(void) {
    pthread_t writer_thread, reader_thread;

    // Optionally initialize the array to a known value (-1).
    for (int i = 0; i < ARRAY_SIZE; i++) {
        shared_data[i] = -1;
    }

    // Create the writer and reader threads.
    pthread_create(&writer_thread, NULL, writer, NULL);
    pthread_create(&reader_thread, NULL, reader, NULL);

    // Wait for both threads to finish.
    pthread_join(writer_thread, NULL);
    pthread_join(reader_thread, NULL);

    return 0;
}

