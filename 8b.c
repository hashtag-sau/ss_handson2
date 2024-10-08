/*
============================================================================
Name : 8b.c
Author : Saurabh Dubey
Description : 8. Write a separate program using signal system call to catch the following signals.
b. SIGINT
Date: 20th sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void Handle_SIGINT(int signalno)
{

  if (signalno == SIGINT)
    printf("SIGINT signal caught %d\n",signalno);
}

int main(void)
{
  signal(SIGINT, Handle_SIGINT);
  printf("\ncan't catch SIGINT\n");
  while(1);
  return 0;
}

// ^CSIGINT signal caught 2
// ^CSIGINT signal caught 2
// ^CSIGINT signal caught 2
