#include "message.h"

// Create message Dynamically
Message* create_msg(const char* id, const char* sender, const char* receiver, const char* content) {
    Message* msg = (Message*)malloc(sizeof(Message));
    if (!msg) return NULL;

    strncpy(msg->id, id, sizeof(msg->id) - 1);
    msg->id[sizeof(msg->id) - 1] = '\0';

    msg->time_sent = time(NULL);

    strncpy(msg->sender, sender, sizeof(msg->sender) - 1);
    msg->sender[sizeof(msg->sender) - 1] = '\0';

    strncpy(msg->receiver, receiver, sizeof(msg->receiver) - 1);
    msg->receiver[sizeof(msg->receiver) - 1] = '\0';

    strncpy(msg->content, content, sizeof(msg->content) - 1);
    msg->content[sizeof(msg->content) - 1] = '\0';

    msg->delivered = 0;

    return msg;
}
