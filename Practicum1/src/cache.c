#include "cache.h"
#include <time.h>
#include <stdio.h>

typedef struct {
    Message* msg;
    time_t last_accessed;
} CacheEntry;

static CacheEntry cache[CACHE_SIZE];

// Initialize all cache entries to NULL
void init_cache() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].msg = NULL;
        cache[i].last_accessed = 0;
    }
}

// Retrieve a message by ID from cache
Message* get_from_cache(int id) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].msg && cache[i].msg->id == id) {
            cache[i].last_accessed = time(NULL); // Update access time
            return cache[i].msg;
        }
    }
    return NULL; // Not found
}

// Add a message to cache if space is available
void put_in_cache(Message* msg) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].msg == NULL) {
            cache[i].msg = msg;
            cache[i].last_accessed = time(NULL);
            return;
        }
    }
    // Cache is full — replacement policy will be added in Part 3
}

// Debugging function to print cache content
void print_cache() {
    printf("Current Cache Content:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].msg) {
            printf("Slot %d: ID=%d, Sender=%s\n", i, cache[i].msg->id, cache[i].msg->sender);
        } else {
            printf("Slot %d: Empty\n", i);
        }
    }
}
