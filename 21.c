/*
============================================================================
Name : .c
Author : Saurabh Dubey
Description :21. Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 20th sep, 2024.
============================================================================
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    //using my_fifo2 for 21 to 21a comms 
    int fd1 = open("./my_fifo", O_RDONLY);
    int fd2 = open("./my_fifo2", O_WRONLY);

    char buf[100];
    read(fd1, buf, 100);
    printf("in 21.c message: %s", buf);

    write(fd2, "hi!! from 21.c", 15);

    return 0;
}