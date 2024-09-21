/*
============================================================================
Name : 8.c
Author : Saurabh Dubey
Description : 8. Write a separate program using signal system call to catch the following signals.

Date: 20th sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void handle_sigalarm(int sig){
    printf("sigalarm caught \n");
    printf("ALARM!! ITIMER_REAL timer expired\n");
}

int main(){

    signal(SIGALRM,handle_sigalarm);
    struct itimerval t;
    t.it_value.tv_sec = 3;
    t.it_value.tv_usec = 0;
    t.it_interval.tv_sec = 0; 
    t.it_interval.tv_usec = 0; 

    setitimer(ITIMER_REAL, &t, NULL);
    sleep(10);
    return 0;
}
// sigalarm caught 
// ALARM!! ITIMER_REAL timer expired

