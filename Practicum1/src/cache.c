#include "cache.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>

typedef struct {
    Message* msg;
    time_t last_accessed;
} CacheEntry;
time_t oldest = LONG_MAX;
static CacheEntry cache[CACHE_SIZE];
static ReplacementPolicy current_policy = LRU_REPLACEMENT; // default

void init_cache() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].msg = NULL;
        cache[i].last_accessed = 0;
    }
}

// Set the replacement policy (random or LRU)
void set_replacement_policy(ReplacementPolicy policy) {
    current_policy = policy;
}

// Search message in cache
Message* get_from_cache(const char* id) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].msg != NULL && strcmp(cache[i].msg->id, id) == 0) {
            cache[i].last_accessed = time(NULL);
            return cache[i].msg;
        }
    }
    return NULL;
}


// Insert message to cache (with replacement)
void put_in_cache(Message* msg) {
    // Try to insert into an empty slot
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].msg == NULL) {
            cache[i].msg = msg;
            cache[i].last_accessed = time(NULL);
            return;
        }
    }

    // Cache is full → perform replacement
    int replace_index = -1;

    if (current_policy == RANDOM_REPLACEMENT) {
        replace_index = rand() % CACHE_SIZE;
    } else if (current_policy == LRU_REPLACEMENT) {
        time_t oldest = LONG_MAX;
        for (int i = 0; i < CACHE_SIZE; i++) {
            if (cache[i].last_accessed < oldest) {
                oldest = cache[i].last_accessed;
                replace_index = i;
            }
        }
    }

    if (replace_index != -1) {
        if (cache[replace_index].msg != NULL) {
            printf("Replacing slot %d (ID=%s) with message ID %s\n",
                replace_index,
                cache[replace_index].msg->id,
                msg->id);
            free(cache[replace_index].msg);
        }

        cache[replace_index].msg = msg;
        cache[replace_index].last_accessed = time(NULL);
    }

}

void print_cache() {
    printf("===== Cache Content =====\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].msg) {
            printf("Slot %d: ID=%s, Sender=%s, Accessed=%ld\n", i,
                   cache[i].msg->id, cache[i].msg->sender, cache[i].last_accessed);
        } else {
            printf("Slot %d: Empty\n", i);
        }
    }
    printf("=========================\n");
}