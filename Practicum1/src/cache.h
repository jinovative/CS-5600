#ifndef CACHE_H
#define CACHE_H

#include "message.h"

#define CACHE_SIZE 16

// Replacement policy options
typedef enum {
    RANDOM_REPLACEMENT,
    LRU_REPLACEMENT
} ReplacementPolicy;

// Public API
void init_cache();
void set_replacement_policy(ReplacementPolicy policy);
Message* get_from_cache(const char* id); 
void put_in_cache(Message* msg);
void print_cache();

#endif