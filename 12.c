/*
============================================================================
Name : 12.c
Author : Saurabh Dubey
Description :12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process
Date: 20th sep, 2024.
============================================================================
*/

#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main(){


    if(!fork()){
        kill(getppid(),9);
    }

    while(1);
}
//terminal output
//Killed 

//child process status after killing parent
// /proc/12191$ cat status
// Name:	a.out
// Umask:	0002
// State:	R (running)
// Tgid:	12191
// Ngid:	0
// Pid:	12191
// PPid:	1
