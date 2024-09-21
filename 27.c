/*
============================================================================
Name : 27.c
Author : Saurabh Dubey
Description :Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
Date: 20th sep, 2024.
============================================================================
*/
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

struct msgBuffer {
    long mtype;           
    char mtext[100];       
};

int main() {
    key_t key = ftok("filefor_25c", 'a');                // Generate the key
    int msgQid = msgget(key, 0666 | IPC_CREAT);  // if message doesn't exists create otherwise get the message queue

    struct msgBuffer message;

    // Receive messages from the queue with any type by using 0 flag
    msgrcv(msgQid, &message, sizeof(message.mtext), 0, 0);

    printf("the message recieved is : %s\n", message.mtext);

    return 0;
}
//from prog 26.c
//the message recieved is : Hello, this is the first message with mtype 1