/*
============================================================================
Name : .c
Author : Saurabh Dubey
Description :19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
Date: 20th sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    char *fifo_name = "mknode_fifo";

    mknod(fifo_name, S_IFIFO | 0666, 0);

    return 0;
}
