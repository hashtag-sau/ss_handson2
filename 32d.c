/*
============================================================================
Name : 32a.c
Author : Saurabh Dubey
Description :Write a program to implement semaphore to protect any critical section. 
               d. Remove the created semaphore
Date: 20th sep, 2024.
============================================================================
*/
#include <sys/ipc.h>     // ftok()
#include <sys/sem.h>     // semget() and semctl()
#include <stdio.h>       

int main() {
    key_t key = ftok("20.c", 'a');

    int semaphoreId = semget(key, 1, 0);  // Semaphore ID
    
    semctl(semaphoreId, 0, IPC_RMID);   // Remove the semaphore
    return 0; 
}