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

void handle_sigfpe(int signalno)
{
    printf("SIGFPE wrong arithmetic ");
    exit(0);
}

int main(void)
{
  signal(SIGFPE, handle_sigfpe);
  int num = 5/0;
  return 0;
}

// SIGFPE wrong arithmetic