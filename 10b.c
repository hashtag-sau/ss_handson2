/*
============================================================================
Name :10b .c
Author : Saurabh Dubey
Description :10. Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT

Date: 20th sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void handle_sigint(int signum){
    printf("sigint caught!!\n"); 
    exit(1);
}

int main(){
    struct sigaction sa;
    sa.sa_handler = handle_sigint; //setting action in sa
    sa.sa_flags  = 0;
    sigemptyset(&sa.sa_mask); // no other signal will be blocked.
    sigaction(SIGINT, &sa, NULL); //third param is for old/previous sigaction struct

    while(1) sleep(1);
    return 0;
}

//^Csigint caught!!

