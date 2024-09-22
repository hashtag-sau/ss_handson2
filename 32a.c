/*
============================================================================
Name : 32a.c
Author : Saurabh Dubey
Description :Write a program to implement semaphore to protect any critical section. 
              a. Rewrite the ticket number creation program using semaphore
Date: 20th sep, 2024.
============================================================================
*/

#include <sys/ipc.h>    // ftok().
#include <sys/sem.h>    //  semget(), semctl() and semop().
#include <fcntl.h>      // open(), O_CREAT and O_RDWR.
#include <unistd.h>   
#include <stdio.h>      
#include <stdlib.h> 
#include <errno.h>  


struct ticket {
    int number;
};


int main() {
    struct ticket t;

    key_t key = ftok("1a.c", 'a');  
    int semaphoreId = semget(key, 1, IPC_CREAT | 0666);  // Create semaphore     

            // Only initialize the semaphore if it's newly created
        if (semctl(semaphoreId, 0, GETVAL) == -1) {
            // Initialize the semaphore only if it doesn't exist
            int sem_val = 1;                           
            semctl(semaphoreId, 0, SETVAL, sem_val);// Initialize semaphore and setting value of sem_val
        }                   



    int file_fd = open("ticketdb", O_CREAT | O_RDWR | O_EXCL, 0666);//using O_EXCl to check if file already exists
    if (file_fd == -1) {                                            // if it already exists we don't initilize ticket number
        if (errno == EEXIST) {
            // File already exists, open it without O_EXCL
            file_fd = open("ticketdb", O_RDWR);
            if (file_fd == -1) {
                perror("error in opening existing file");
            }
        } else {
            perror("open error");
        }
    } else {// the program comes here if file is created newly
        t.number = 46; // we now lock and write ticket number to newly created file

        struct sembuf ops = {0, -1, 0}; 
        semop(semaphoreId, &ops, 1); 
        lseek(file_fd, 0, SEEK_SET); 
        write(file_fd, &t, sizeof(t));
        ops.sem_op = 1;
        semop(semaphoreId, &ops, 1); //unlocking
        return 1;
    }


    struct sembuf operations = {0, -1, 0};
    //  operations.sem_op = 1;                          // Unlock semaphore
    // semop(semaphoreId, &operations, 1); 
    //  operations.sem_op = 1;                          // Unlock semaphore
    // semop(semaphoreId, &operations, 1); 
    
    printf("waiting for lock\n");
    //struct sembuf 
    operations.sem_op = -1;  // Lock semaphore                                   
    semop(semaphoreId, &operations, 1);             // Begin critical section

    printf("lock acquired\n");
    printf("in critical section for 10 second\n");

    read(file_fd,&t,sizeof(t));
    printf("current ticket value: %d", t.number);

    t.number++;  
    lseek(file_fd, 0, SEEK_SET); 
    write(file_fd, &t, sizeof(t));                     // Overwrite the file.
    close(file_fd);

    sleep(10);
    operations.sem_op = 1;                          // Unlock semaphore
    semop(semaphoreId, &operations, 1);             // End critical section
    printf("exited critical section ");
    return 0;
}

// waiting for lock
// lock acquired
// in critical section for 10 second
// current ticket value: 62exited critical section