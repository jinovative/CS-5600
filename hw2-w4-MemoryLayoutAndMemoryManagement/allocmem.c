/*
 * allocmem.c / Asignment_2_Part_2_1_Memory Management
 *
 * JinYoung Park / CS5600 / Northeastern University
 * Spring 2025 / Jan 21, 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

// allocate static memory(5MB)
static char static_mem[5 * 1024 * 1024]; // 5MB of static memory

// stack memory function
void allocate_stack_memory(size_t size) {
    char stack_mem[size]; // 1MB stack memory
    printf("1MB allocated on stack.\n");
}

int main() {
    printf("Starting memory allocation...\n");

    // allocate heap memory(10MB)
    char *heap_mem = malloc(10 * 1024 * 1024);
    if (!heap_mem) {
        return -1;
    }
    printf("10MB heap memory allocated.\n");

    // use static memory 
    for (int i = 0; i < sizeof(static_mem); i++) {
        static_mem[i] = 0; // reset
    }
    printf("5MB static memory initialized.\n");

    // allocate stack memory
    allocate_stack_memory(1 * 1024 * 1024);

    // free heap memory
    free(heap_mem);
    printf("10MB heap memory free.\n");

    return 0;
    // When a program exits and the associated process is terminated,
    // the operating system automatically reclaims all memory allocated by the program, 
    // including heap, stack, and static memory.

}
