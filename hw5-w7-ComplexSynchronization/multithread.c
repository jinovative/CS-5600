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
 
void *worker(void *data)
{
    char *name = (char*)data;
    for (int i = 0; i < 120; i++)
    {
        usleep(50000);  // Sleep for 50 milliseconds
        printf("Hi from thread name = %s\n", name);
    }
    printf("Thread %s done!\n", name);
    return NULL;
}
 
int main(void)
{
    pthread_t th1, th2;
    
    // Create two threads with names "X" and "Y"
    pthread_create(&th1, NULL, worker, "X");
    pthread_create(&th2, NULL, worker, "Y");
    
    sleep(1);
    
    // Print the thread ID along with cancellation message for thread Y
    printf("====> Cancelling Thread: %lu (Y)\n", (unsigned long)th2);
    pthread_cancel(th2);
    
    usleep(100000);  // Wait for 100 milliseconds
    
    // Print the thread ID along with cancellation message for thread X
    printf("====> Cancelling Thread: %lu (X)\n", (unsigned long)th1);
    pthread_cancel(th1);
    
    printf("Exiting from main program\n");
    return 0;
}

