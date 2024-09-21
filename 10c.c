/*
============================================================================
Name :10a .c
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

void handle_sigfpe(int signum){
    printf("you got segfpe!!! be careful!!\n"); 
    exit(1);
}

int main(){
    struct sigaction sa;
    sa.sa_handler = handle_sigfpe; //setting action in sa
    sa.sa_flags  = 0;
    sigemptyset(&sa.sa_mask); // no other signal will be blocked.
    sigaction(SIGFPE, &sa, NULL); //third param is for old/previous sigaction struct
    int num = 5/0;
    return 0;
}

//you got segfpe!!! be careful!!