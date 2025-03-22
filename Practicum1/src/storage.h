#ifndef STORAGE_H
#define STORAGE_H

#include "message.h"

#define STORAGE_FILE "data/messages.db"  // save as file 

// Declare function for saving message
void store_msg(const Message* msg);

// Search message using ID
Message* retrieve_msg(int id);

#endif // STORAGE_H

