/*
============================================================================
Name : .c
Author : Saurabh Dubey
Description :29. Write a program to remove the message queue
Date: 20th sep, 2024.
============================================================================
*/
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
int main() {
    key_t key = ftok("filefor_25c", 'a');
    int msgQid = msgget(key, 0666);   // get the current message queue
    
    if (msgctl(msgQid, IPC_RMID, NULL) == -1) { // Remove the message queue
        perror("msgctl");
        return 1;
    }

    printf("Message queue removed\n");
    return 0;
}
//first add message with prog no 26
//Message queue removed