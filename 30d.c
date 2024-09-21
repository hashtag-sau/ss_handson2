/*
============================================================================
Name : 30.c
Author : Saurabh Dubey
Description :Write a program to create a shared memory. 
              d. Remove the shared memory 
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
   shmdt(sharedmemAddr);
   shmctl(sharedmemid,IPC_RMID,NULL);
}

//before removing
//  ipcs -m

// ------ Shared Memory Segments --------
// key        shmid      owner      perms      bytes      nattch     status      
// 0x00000000 131076     h1n1cov    600        524288     2          dest         
// 0x00000000 6          h1n1cov    600        524288     2          dest         
// 0x00000000 9          h1n1cov    600        268435456  2          dest         
// 0x00000000 65547      h1n1cov    600        524288     2          dest         
// 0x00000000 65548      h1n1cov    600        4194304    2          dest         
// 0x61080586 131092     h1n1cov    774        1024       0                       
// 0x00000000 98327      h1n1cov    600        524288     2          dest         
// 0x00000000 131097     h1n1cov    600        524288     2          dest         
// 0x00000000 26         h1n1cov    600        524288     2          dest         
// 0x00000000 33         h1n1cov    600        4194304    2          dest         
// 0x00000000 38         h1n1cov    600        524288     2          dest         
// 0x00000000 46         h1n1cov    600        524288     2          dest         
// 0x00000000 53         h1n1cov    600        524288     2          dest         
// 0x00000000 54         h1n1cov    600        4194304    2          dest         
// 0x00000000 55         h1n1cov    600        134217728  2          dest         
// 0x00000000 56         h1n1cov    600        524288     2          dest         
// 0x00000000 57         h1n1cov    600        393216     2          dest


//after removing
//  ipcs -m

// ------ Shared Memory Segments --------
// key        shmid      owner      perms      bytes      nattch     status      
// 0x00000000 131076     h1n1cov    600        524288     2          dest         
// 0x00000000 6          h1n1cov    600        524288     2          dest         
// 0x00000000 9          h1n1cov    600        268435456  2          dest         
// 0x00000000 65547      h1n1cov    600        524288     2          dest         
// 0x00000000 65548      h1n1cov    600        4194304    2          dest         
// 0x00000000 98327      h1n1cov    600        524288     2          dest         
// 0x00000000 131097     h1n1cov    600        524288     2          dest         
// 0x00000000 26         h1n1cov    600        524288     2          dest         
// 0x00000000 33         h1n1cov    600        4194304    2          dest         
// 0x00000000 38         h1n1cov    600        524288     2          dest         
// 0x00000000 46         h1n1cov    600        524288     2          dest         
// 0x00000000 53         h1n1cov    600        524288     2          dest         
// 0x00000000 54         h1n1cov    600        4194304    2          dest         
// 0x00000000 55         h1n1cov    600        134217728  2          dest         
// 0x00000000 56         h1n1cov    600        524288     2          dest         
// 0x00000000 57         h1n1cov    600        393216     2          dest  