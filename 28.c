/*
============================================================================
Name : .c
Author : Saurabh Dubey
Description :28. Write a program to change the exiting message queue permission
Date: 20th sep, 2024.
============================================================================
*/

#include <sys/types.h>   
#include <sys/ipc.h>    
#include <sys/msg.h>    
#include <stdio.h>      

int main() {
    key_t key = ftok("filefor_25c", 'a');                                                   // Generate a unique key

    int msgQid = msgget(key, 0); // Get the existing message queue ID

    struct msqid_ds msgQueDataStruct;                              
    msgctl(msgQid, IPC_STAT, &msgQueDataStruct);  // Get current message que stat
    printf("Current permissions: %o\n", msgQueDataStruct.msg_perm.mode & 0777);  

    msgQueDataStruct.msg_perm.mode = 0660;                                          
    msgctl(msgQid, IPC_SET, &msgQueDataStruct); //setting new info using IPC_SET, only permission was changed 

    printf("Updated permissions: %o\n", msgQueDataStruct.msg_perm.mode & 0777); 

    return 0;
}
// Current permissions: 666
// Updated permissions: 660