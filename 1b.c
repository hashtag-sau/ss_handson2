/*
============================================================================
Name : 1b.c
Author : Saurabh Dubey
Description :1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
Date: 20th sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

void handle_sigalarm(int sig){
    printf("ALARM!! ITIMER_VIRTUAL timer expired\n");
}

int main(){

    signal(SIGVTALRM,handle_sigalarm);
    struct itimerval t;
    t.it_value.tv_sec = 10;
    t.it_value.tv_usec = 0;
    t.it_interval.tv_sec = 0; 
    t.it_interval.tv_usec = 10; 

    setitimer(ITIMER_VIRTUAL, &t, NULL);
    while(1); 
}

// ALARM!! ITIMER_VIRTUAL timer expired
// ALARM!! ITIMER_VIRTUAL timer expired
// ALARM!! ITIMER_VIRTUAL timer expired
// ALARM!! ITIMER_VIRTUAL timer expired
// ALARM!! ITIMER_VIRTUAL timer expired
// ALARM!! ITIMER_VIRTUAL timer expired
// ALARM!! ITIMER_VIRTUAL timer expired
// ALARM!! ITIMER_VIRTUAL timer expired
// ALARM!! ITIMER_VIRTUAL timer expired
// ALARM!! ITIMER_VIRTUAL timer expired
// ALARM!! ITIMER_VIRTUAL timer expired
// ALARM!! ITIMER_VIRTUAL timer expired
// ALARM!! ITIMER_VIRTUAL timer expired
// ALARM!! ITIMER_VIRTUAL timer expired
// ALARM!! ITIMER_VIRTUAL timer expired
// ALARM!! ITIMER_VIRTUAL timer expired



