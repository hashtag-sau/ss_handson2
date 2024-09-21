/*
============================================================================
Name : 8.c
Author : Saurabh Dubey
Description : 8. Write a separate program using signal system call to catch the following signals.

Date: 20th sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

void handle_sigalrm(int signalno)
{
    printf("SIGALARM wake up!!! ");
}

int main(void)
{
  signal(SIGALRM, handle_sigalrm);
    alarm(3);
    sleep(10);
  return 0;
}

// SIGALARM wake up!!!