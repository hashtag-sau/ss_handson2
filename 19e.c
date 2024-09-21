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
#include <sys/stat.h>

int main() {
    char *fifo_name = "mkfifo_fifo";

    mkfifo(fifo_name, 0666);

    return 0;
}
