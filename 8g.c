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
    printf("caught sigprof \n");
    printf("ALARM!! ITIMER_PROF timer expired\n");
}

int main(){

    signal(SIGPROF,handle_sigalarm);
    struct itimerval t;
    t.it_value.tv_sec = 10;
    t.it_value.tv_usec = 0;
    t.it_interval.tv_sec = 0; 
    t.it_interval.tv_usec = 0; 

    setitimer(ITIMER_PROF, &t, NULL);
    while(1) ; 

return 0;
}
// caught sigprof 
// ALARM!! ITIMER_PROF timer expired
// ^C