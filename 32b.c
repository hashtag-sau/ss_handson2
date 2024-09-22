/*
============================================================================
Name : 32a.c
Author : Saurabh Dubey
Description :Write a program to implement semaphore to protect any critical section. 
              b. Protect shared memory from concurrent write access
Date: 20th sep, 2024.
============================================================================
*/
#include <sys/ipc.h>        // For using ftok().
#include <sys/sem.h>        // semget(), semctl(), and semop().
#include <sys/shm.h>        // shmget(), shmat(), and shmctl().
#include <fcntl.h>         
#include <unistd.h>     
#include <stdio.h>          

union semaphore {
    int val;
};

struct ticket{
    int ticket_count;         
};

int main() {
    key_t key = ftok("1a.c", 'O');  
    int shm_id = shmget(key, sizeof(struct ticket), IPC_CREAT | 0666);  // Create shared memory

    struct ticket *ticket = (struct ticket *)shmat(shm_id, NULL, 0);  // Attach shared memory

    key_t sem_key = ftok("5.c", 'a');  
    int semaphoreId = semget(sem_key, 1, IPC_CREAT | 0666);  // Create semaphore

          // Only initialize the semaphore if it's newly created
        if (semctl(semaphoreId, 0, GETVAL) == -1) {
            // Initialize the semaphore only if it doesn't exist
            printf("helo\n");
            int sem_val = 1;                           
            semctl(semaphoreId, 0, SETVAL, sem_val);// Initialize semaphore and setting value of sem_val
        } 
        
        ticket->ticket_count = 46;  // Initialize shared ticket

        struct sembuf operations = {0, -1, 0};  // Lock semaphore
        semop(semaphoreId, &operations, 1);     // Begin critical section

        ticket->ticket_count++;                     
        printf("current ticket number: %d\n", ticket->ticket_count);
        sleep(10); 

        operations.sem_op = 1;                  // Unlock semaphore
        semop(semaphoreId, &operations, 1);     // End critical section

    shmdt(ticket);                      // Detach shared memory
    shmctl(shm_id, IPC_RMID, NULL);     // Remove shared memory

    return 0;
}