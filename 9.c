/*
============================================================================
Name : 9.c
Author : Saurabh Dubey
Description :Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 20th sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(){
    printf("program started\n");
    printf("first signal will be ignored\n");
    
    signal(SIGINT,SIG_IGN);
    printf("give SIGINT within 4 second and it will be ignored\n");
    sleep(4);
    signal(SIGINT,SIG_DFL);
    while(1);
    return 0;
}
// program started
// first signal will be ignored
// give SIGINT within 4 second and it will be ignored
// ^C^C
