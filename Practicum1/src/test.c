#include "message.h"
#include "storage.h"
#include "cache.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define TEST_MSG_COUNT 100  // total messages stored initially

void run_cache_test(int access_count) {
    int hits = 0;
    int misses = 0;

    srand(time(NULL));

    // Step 1: Store 100 messages in disk and cache
    for (int i = 0; i < TEST_MSG_COUNT; i++) {
        char id[32];
        char content[64];

        sprintf(id, "%d", i);  // ID를 문자열로 바꾸기
        sprintf(content, "Message #%s", id);

        Message* msg = create_msg(id, "Tester", "Receiver", content);
        store_msg(msg);
        free(msg);
    }


    // Step 2: Access messages randomly
    for (int i = 0; i < access_count; i++) {
        char id[32];
        sprintf(id, "%d", rand() % TEST_MSG_COUNT); 

        // First, check cache directly (simulate "peek" before retrieve_msg)
        if (get_from_cache(id)) {
            hits++;
        } else {
            misses++;
        }

        // Actual retrieval (may load into cache)
        Message* msg = retrieve_msg(id);
        if (msg) {
            printf("Accessed message ID %s\n", msg->id);
        }
        if (!get_from_cache(id)) {
            // Should never happen because retrieve_msg loads into cache
            printf("Warning: failed to cache message %s after access.\n", id);
        }
    }

    // Step 3: Output result
    printf("\n=== Cache Test Report ===\n");
    printf("Total accesses: %d\n", access_count);
    printf("Cache Hits: %d\n", hits);
    printf("Cache Misses: %d\n", misses);
    printf("Hit Ratio: %.2f%%\n", (hits * 100.0) / access_count);
}
