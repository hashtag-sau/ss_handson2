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

void handle_sigsegv(int signum){
    printf("you got seg fault!!! be careful!!\n"); 
    exit(1);
}

int main(){
    struct sigaction sa;
    sa.sa_handler = handle_sigsegv; //setting action in sa
    sa.sa_flags  = 0;
    sigemptyset(&sa.sa_mask); // no other signal will be blocked.
    sigaction(SIGSEGV, &sa, NULL); //third param is for old/previous sigaction struct

    int *a;
    int num;
    num = *(a+10);
    return 0;
}
//you got seg fault!!! be careful!!