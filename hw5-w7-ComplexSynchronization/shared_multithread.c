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

// Array shared globaly by all threads
int shared_data[ARRAY_SIZE];

// Writer thread to add different values to each element.
void *writer(void *arg) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        // Different value for each index
        shared_data[i] = (i + 1) * 3; 
        printf("Writer: shared_data[%d] = %d\n", i, shared_data[i]);
        usleep(100000); // Sleep
    }
    return NULL;
}

// Reader thread to read and print the global array.
void *reader(void *arg) {
    // Read and print the global array
    for (int j = 0; j < 5; j++) {
        printf("Reader: current shared_data: ");
        for (int i = 0; i < ARRAY_SIZE; i++) {
            printf("%d ", shared_data[i]);
        }
        printf("\n");
        usleep(200000); // Sleep
    }
    return NULL;
}

int main(void) {
    pthread_t writer_thread, reader_thread;

    // Initialize the empty array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        shared_data[i] = -1;
    }

    // Create writer and reader threads
    pthread_create(&writer_thread, NULL, writer, NULL);
    pthread_create(&reader_thread, NULL, reader, NULL);

    // Wait for both threads
    pthread_join(writer_thread, NULL);
    pthread_join(reader_thread, NULL);

    return 0;
}

