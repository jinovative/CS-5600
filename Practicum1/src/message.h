#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Set maximum context volume
#define MAX_CONTENT_SIZE 512

// Structure of Message
typedef struct message {
    char id[64];
    time_t time_sent;
    char sender[50];
    char receiver[50];
    char content[MAX_CONTENT_SIZE];  
    int delivered;
} Message;

// Declare funciton of message
Message* create_msg(const char* id, const char* sender, const char* receiver, const char* content); 


#endif 