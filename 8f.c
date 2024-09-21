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
    printf("caught SIGVTALRM\n");
    printf("ALARM!! ITIMER_VIRTUAL timer expired\n");
}

int main(){

    signal(SIGVTALRM,handle_sigalarm);
    struct itimerval t;
    t.it_value.tv_sec = 0;
    t.it_value.tv_usec = 1000; //1milliseconds
    t.it_interval.tv_sec = 0; 
    t.it_interval.tv_usec = 0; 

    setitimer(ITIMER_VIRTUAL, &t, NULL);
    while(1) usleep(10);
return 0;
}

// caught SIGVTALRM                         // the program ran for 20 seconds(real time) and then printed this 
// ALARM!! ITIMER_VIRTUAL timer expired     // cause it only counts the cpu time program is taking    
// ^C
