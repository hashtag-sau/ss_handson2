/*
============================================================================
Name : 32a.c
Author : Saurabh Dubey
Description :Write a program to implement semaphore to protect any critical section. 
              c. Protect multiple pseudo resources (may be two) using counting semaphore
Date: 20th sep, 2024.
============================================================================
*/

#include <sys/ipc.h>     // For using ftok().
#include <sys/sem.h>     // semget(), semctl(), and semop().
#include <stdio.h>       
#include <fcntl.h>       
#include <unistd.h>      




void wait_semaphore(int semId) {
    struct sembuf op = {0, -1, 0}; // P operation (wait)
    semop(semId, &op, 1);
}

void signal_semaphore(int semId) {
    struct sembuf op = {0, 1, 0}; // V operation (signal)
    semop(semId, &op, 1);
}

struct ticket {
    int ticket_count; 
};

int main() {
    key_t key = ftok("20.c", 'a');         
    int semaphoreId = semget(key, 1, IPC_CREAT | 0666); //create or get if it already exists
    int set_val = 2; // Counting semaphore initialized to 2 resources

    semctl(semaphoreId, 0, SETVAL, set_val); // Set the initial value

    int file_fd= open("someResource", O_CREAT | O_RDWR, 0666); // Open file for resources


    struct ticket tkt = {46}; // Initial ticket number

        wait_semaphore(semaphoreId); // Lock semaphore for ticket resource
        printf("current ticket value: %d \n",tkt.ticket_count);
        tkt.ticket_count++;

        wait_semaphore(semaphoreId); // Lock semaphore for file resource
        printf("writing to file \n");
        lseek(file_fd, 0, SEEK_SET); // Move to start of file
        write(file_fd, &tkt, sizeof(tkt)); // Write resources to file

        signal_semaphore(semaphoreId); // Unlock semaphore for file resource
        signal_semaphore(semaphoreId); // Unlock semaphore for ticket resource
                              
    return 0;
}

// current ticket value: 46 
// writing to file 
