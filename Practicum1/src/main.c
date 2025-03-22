#include "message.h"
#include "storage.h"

int main() {
    // create message
    Message* msg1 = create_msg(1, "A", "B", "Hello, folks! How are you?");
    if (!msg1) {
        return 1;
    }

    // save message
    store_msg(msg1);
    printf("Saved message: %s -> %s: \"%s\"\n",
           msg1->sender, msg1->receiver, msg1->content);

    // search message
    Message* retrieved_msg = retrieve_msg(1);
    if (retrieved_msg) {
        printf("Result: %s -> %s: \"%s\"\n",
               retrieved_msg->sender, retrieved_msg->receiver, retrieved_msg->content);
        free(retrieved_msg); // release memory
    } else {
        printf("Cannot find message.\n");
    }

    // release allocated message
    free(msg1);
    return 0;
}

