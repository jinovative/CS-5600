/*
 * pqueuepmain.c / Assignment5 / Week7 / Part3
 *
 * JinYoung Park / CS5600 / Northeastern University
 * Spring 2025 / Feb 6, 2025
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define BUF_SIZE 15    
int buffer[BUF_SIZE];
int num = 0;
pthread_mutex_t mut;
pthread_cond_t cond; 

int totalProduced = 0;
int totalConsumed = 0;


void *producer(void *param);
void *consumer(void *param);

int main(int argc, char *argv[])
{
    pthread_t producers[2], consumers[2];
    int i;

    if(pthread_mutex_init(&mut, NULL) != 0) {
        perror("pthread_mutex_init");
        exit(1);
    }
    if(pthread_cond_init(&cond, NULL) != 0) {
        perror("pthread_cond_init");
        exit(1);
    }
    
    // Create producer threads
    for(i = 0; i < 2; i++) {
        if (pthread_create(&producers[i], NULL, producer, NULL) != 0) {
            perror("pthread_create");
            exit (1);
        }
    } 

    // Create consumer threads
    for(i = 0; i < 2; i++) {
        if (pthread_create(&consumers[i], NULL, consumer, NULL) != 0) {
            perror("pthread_create");
            exit (1);
        }
    }

    // Wait for all producer threads to exit
    for(i = 0; i < 2; i++) {
        pthread_join(producers[i], NULL);
    }

    // Wait for all consumer threads to exit
    for(i = 0; i < 2; i++) {
        pthread_join(consumers[i], NULL);
    }
    
    printf("WE ARE DONE\n");
    return 0;
}

void *producer(void *param)
{
    int localCount = 0;  
    while(1) {
        pthread_mutex_lock(&mut);
        // Check total production limit has been reached.
        if (totalProduced >= 30) {
            pthread_mutex_unlock(&mut);
            printf("Producer thread %lu: produced 30 items, exiting.\n", (unsigned long)pthread_self());
            // Wake up any waiting threads
            pthread_cond_broadcast(&cond);
            pthread_exit(NULL);
        }
        // Wait if the buffer is full.
        while (num == BUF_SIZE)
            pthread_cond_wait(&cond, &mut);

        // Item to generate a unique value.
        int item = totalProduced + 1;
        buffer[num] = item;
        num++;
        totalProduced++;
        printf("Producer thread %lu: Item %d, Buffer size %d, Total: %d\n",
               (unsigned long)pthread_self(), item, num, totalProduced);

        pthread_mutex_unlock(&mut);
        pthread_cond_broadcast(&cond);
        sleep(1);
        localCount++;
    }
    return NULL;
}

void *consumer(void *param)
{
    while (1) {
        pthread_mutex_lock(&mut);

        // Check if total consumption limit has been reached.
        if (totalConsumed >= 30) {
            pthread_mutex_unlock(&mut);
            printf("Consumer thread %lu: consumed 30 items, exiting.\n", (unsigned long)pthread_self());
            pthread_cond_broadcast(&cond);
            pthread_exit(NULL);
        }
        // Wait if the buffer is empty.
        while (num == 0)
            pthread_cond_wait(&cond, &mut);

        // Remove the first item in the buffer.
        int item = buffer[0];
        // Shift the remaining items to the left.
        for (int j = 0; j < num - 1; j++) {
            buffer[j] = buffer[j+1];
        }
        num--;
        totalConsumed++;
        printf("Consumer thread %lu: Item %d, buffer size%d, Total: %d\n",
               (unsigned long)pthread_self(), item, num, totalConsumed);

        pthread_mutex_unlock(&mut);
        pthread_cond_broadcast(&cond); 
        sleep(3); 
    }
    return NULL;
}

