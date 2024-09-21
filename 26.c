/*
============================================================================
Name : .c
Author : Saurabh Dubey
Description :26. Write a program to send messages to the message queue. Check $ipcs -q
Date: 20th sep, 2024.
============================================================================
*/

#include <sys/types.h>  
#include <sys/ipc.h>    
#include <sys/msg.h>    
#include <stdio.h>     
    struct msgBuffer {    // Define the message buffer structure
        long mtype;
        char mtext[100];                             
    }; 

int main() {
    key_t key = ftok("filefor_25c", 'a');              
    int msgQid = msgget(key, IPC_CREAT | 0666); // Create a message queue with read and write permissions


    // Initialize two messages with different types
    struct msgBuffer msg1 = {1, "message 1 with mtype 1"};
    struct msgBuffer msg2 = {2, "this is message 2 with mtype 2"};

    msgsnd(msgQid, (void *)&msg1, sizeof(msg1.mtext), IPC_NOWAIT);     // Send the first message to the message queue
    msgsnd(msgQid, (void *)&msg2, sizeof(msg2.mtext), IPC_NOWAIT);     // Send the second message to the message queue


    return 0;
}