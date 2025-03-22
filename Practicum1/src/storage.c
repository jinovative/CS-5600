#include "storage.h"

// functiton for saving message 
void store_msg(const Message* msg) {
    FILE* file = fopen(STORAGE_FILE, "a"); // 파일을 append 모드로 열기
    if (!file) {
        fprintf(stderr, "Cannot open this file: %s\n", STORAGE_FILE);
        return;
    }

    // Save message as binary 
    fwrite(msg, sizeof(Message), 1, file);
    fclose(file);
}

// Function search message on ID
Message* retrieve_msg(int id) {
    FILE* file = fopen(STORAGE_FILE, "r"); // Open file as read mode
    if (!file) {
        fprintf(stderr, "Cannot open this file: %s\n", STORAGE_FILE);
        return NULL;
    }

    Message* msg = (Message*)malloc(sizeof(Message));
    if (!msg) {
        fprintf(stderr, "Fail to allocate\n");
        fclose(file);
        return NULL;
    }

    // compare each message depends on ID
    while (fread(msg, sizeof(Message), 1, file)) {
        if (msg->id == id) {
            fclose(file);
            return msg;  // return message
        }
    }

    fclose(file);
    free(msg);
    return NULL;  // return NULL if not find
}

