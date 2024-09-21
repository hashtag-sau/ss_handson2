/*
============================================================================
Name : .c
Author : Saurabh Dubey
Description :11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call
Date: 20th sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int count = 5; //my program will ignore first five sigint 

// First signal handler to ignore SIGINT
void ignore_sigint(int sig) {
    printf("sigint caught and ignored\n");
    count--;
}

// Main function
int main() {
    struct sigaction sa, old_sa;

    sa.sa_handler = ignore_sigint; //same as giving function for action but we have to make our function such that it ignores the signal
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, &old_sa); //setting sigaction with new sa action and retreiving old sa which would be default

    while (count) {
        sleep(1);
    }

   sigaction(SIGINT, &old_sa, NULL) ;// resetting to old default action
   

    printf("now default action of sigint will be taken\n");
    while(1) sleep(1);

    return 0;
}
// ^Csigint caught and ignored
// ^Csigint caught and ignored
// ^Csigint caught and ignored
// ^Csigint caught and ignored
// ^Csigint caught and ignored
// now default action of sigint will be taken
// ^C