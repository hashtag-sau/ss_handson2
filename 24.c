/*
============================================================================
Name : .c
Author : Saurabh Dubey
Description :24. Write a program to create a message queue and print the key and message queue id
Date: 20th sep, 2024.
============================================================================
*/

#include <stdio.h>      
#include <sys/ipc.h>    
#include <sys/msg.h> 

int main() {
int key, msgid;
key = ftok(".", 'a'); //learn this later
msgid = msgget(key, IPC_CREAT|IPC_EXCL|0744); //create and return message queue id
// %0x for Hexadecimal value
printf("key=0x%0x\t msgid=%d\n", key, msgid);

    return 0;
}
//key=0x61080015   msgid=-1