/*
============================================================================
Name : 30.c
Author : Saurabh Dubey
Description :Write a program to create a shared memory. 
               b. Attach with O_RDONLY and check whether you are able to overwrite. 
Date: 20th sep, 2024.
============================================================================
*/

#include <stdio.h>      
#include <sys/ipc.h>      
#include <sys/shm.h>      
#include <string.h> 


int main() {
    key_t key = ftok("filefor_25c", 'a'); 
    int sharedmemid = shmget(key, 1024, IPC_CREAT | 0744); 
    
    
   void * sharedmemAddr = shmat(sharedmemid, 0, SHM_RDONLY);
    memcpy(sharedmemAddr,"hi there!!",11); // Trying to overwrite will fail.
                                    

}
//Segmentation fault (core dumped)