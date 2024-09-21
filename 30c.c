/*
============================================================================
Name : 30.c
Author : Saurabh Dubey
Description :Write a program to create a shared memory. 
              a. Write some data to the shared memory
Date: 20th sep, 2024.
============================================================================
*/


#include <stdio.h>      
#include <sys/ipc.h>      
#include <sys/shm.h>      
#include <string.h>       


int main() {
   key_t key = ftok("filefor_25c", 'a');                       
    int sharedmemid = shmget(key, 128, IPC_CREAT | 0774); // Create 128 bytes of shared memory

    
    void* sharedmemAddr = shmat(sharedmemid, NULL, 0);  // Link to the shared memory 
    memcpy(sharedmemAddr,"hello world!!",14);   // Write to shared mem 

    shmdt(sharedmemAddr); //unlink /detach
}