#ifndef CACHE_H
#define CACHE_H

#include "message.h"

#define CACHE_SIZE 16  // Maximum number of messages in cache

// Initializes the cache system
void init_cache();

// Retrieves a message from the cache by ID
Message* get_from_cache(int id);

// Adds a message to the cache (if full, does not replace — Part 3 will handle that)
void put_in_cache(Message* msg);

// Helper function to print cache content (for debugging)
void print_cache();

#endif
