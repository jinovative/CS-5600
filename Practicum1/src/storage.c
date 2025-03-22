#include "storage.h"
#include "cache.h"  // include cache

void store_msg(const Message* msg) {
    FILE* file = fopen(STORAGE_FILE, "a");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", STORAGE_FILE);
        return;
    }

    fwrite(msg, sizeof(Message), 1, file);
    fclose(file);

    // Add to cache
    Message* msg_copy = (Message*)malloc(sizeof(Message));
    if (msg_copy) {
        memcpy(msg_copy, msg, sizeof(Message));
        put_in_cache(msg_copy); // Store a copy in cache
    }
}

// Function search message on ID
Message* retrieve_msg(int id) {
    // First check cache
    Message* cached_msg = get_from_cache(id);
    if (cached_msg) {
        printf("[Cache] Message ID %d found in cache.\n", id);
        return cached_msg;
    }

    // If not found in cache, check disk
    FILE* file = fopen(STORAGE_FILE, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", STORAGE_FILE);
        return NULL;
    }

    Message* msg = (Message*)malloc(sizeof(Message));
    while (fread(msg, sizeof(Message), 1, file)) {
        if (msg->id == id) {
            fclose(file);

            // Store a copy in cache
            Message* msg_copy = (Message*)malloc(sizeof(Message));
            if (msg_copy) {
                memcpy(msg_copy, msg, sizeof(Message));
                put_in_cache(msg_copy);
            }
            return msg;
        }
    }

    fclose(file);
    free(msg);
    return NULL; // Not found
}

