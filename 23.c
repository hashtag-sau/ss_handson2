/*
============================================================================
Name : .c
Author : Saurabh Dubey
Description :23. Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 20th sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>

int main() {
    long PIPE_BUF, OPEN_MAX;
    OPEN_MAX = sysconf(_SC_OPEN_MAX);
    PIPE_BUF = pathconf(".", _PC_PIPE_BUF);

    printf("max number of files that can be opened : %ld\n", OPEN_MAX);
    printf("max size of pipe : %ld \n", PIPE_BUF);
    return 0;
}

// max number of files that can be opened : 1048576
// max size of pipe : 4096 
