#include "message.h"
#include "storage.h"
#include "cache.h"

int main() {
    init_cache(); // Initialize the cache

    // Create and store a message
    Message* msg1 = create_msg(1, "Jin", "David", "Hello David!");
    store_msg(msg1);
    printf("Message stored: %s -> %s\n", msg1->sender, msg1->receiver);
    free(msg1); // Free original pointer (copy is cached)

    // Retrieve the message (should hit cache on second access)
    Message* fetched = retrieve_msg(1); // From disk, will be cached
    if (fetched) {
        printf("Retrieved: %s -> %s | %s\n", fetched->sender, fetched->receiver, fetched->content);
    }

    Message* fetched2 = retrieve_msg(1); // From cache
    if (fetched2) {
        printf("Retrieved Again (Cache): %s\n", fetched2->content);
    }

    print_cache(); // print cache content

    return 0;
}


