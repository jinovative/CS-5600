#include "message.h"

// Create message Dynamically
Message* create_msg(int id, const char* sender, const char* receiver, const char* content) {
    // Allocate memory
    Message* msg = (Message*)malloc(sizeof(Message));
    if (!msg) {
        fprintf(stderr, "Fail to allocate!\n");
        return NULL;
    }

    // Reset message field 
    msg->id = id;
    msg->time_sent = time(NULL);  // save time 
    strncpy(msg->sender, sender, sizeof(msg->sender) - 1);
    msg->sender[sizeof(msg->sender) - 1] = '\0'; // guarantee end of message
    strncpy(msg->receiver, receiver, sizeof(msg->receiver) - 1);
    msg->receiver[sizeof(msg->receiver) - 1] = '\0';
    strncpy(msg->content, content, sizeof(msg->content) - 1);
    msg->content[sizeof(msg->content) - 1] = '\0';
    msg->delivered = 0;  // Initial state is 0(None-delivered)

    return msg;
}

