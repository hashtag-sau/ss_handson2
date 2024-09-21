/*
============================================================================
Name : .c
Author : Saurabh Dubey
Description :Write a program to create a semaphore and initialize value to the semaphore. 
              a. Create a binary semaphore 

Date: 20th sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key = ftok("filefor_25c", 'a'); // generate unique key for semaphore
    int semaphoreID = semget(key, 1, IPC_CREAT | 0666); // Create a semaphore set with 1 semaphore


    if (semctl(semaphoreID, 0, SETVAL, 1) == -1) { //second param is index of semaphore from set, our set has only one 
        perror("semctl"); //fourth param is value to be initialized
        return -1;
    }

    printf("created and initialized semaphore with value 1, semaphoreid is %d\n",semaphoreID);
    return 0;
}

//ipcs -s

// ------ Semaphore Arrays --------
// key        semid      owner      perms      nsems     
// 0x61080586 0          h1n1cov    666        1  