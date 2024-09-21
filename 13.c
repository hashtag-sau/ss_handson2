/*
============================================================================
Name : 13.c
Author : Saurabh Dubey
Description :13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 20th sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigstop(int signum){
    printf("caught sigstop");
}

int main() {

    signal(SIGSTOP,handle_sigstop);
    printf("send me a sigstop here's my pid: %d\n", getpid());
    while (1);

    return 0;
}
//conclusion sigstop was not caugtable. it stopped the program and our program was not able to catch or handle it.
//terminal 1**
// send me a sigstop here's my pid: 13549

// [1]+  Stopped                 ./a.out

//terminal2 **
// Enter the pid of program to stop 13549
// Sent SIGSTOP
