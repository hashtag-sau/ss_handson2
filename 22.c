/*
============================================================================
Name : .c
Author : Saurabh Dubey
Description :22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 20th sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/select.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    int fd = open("myfifo", O_RDONLY | O_NONBLOCK);

    fd_set set;
    FD_ZERO(&set); //clear fd set
    FD_SET(fd, &set); //add our fd to fdset

    struct timeval timeout = {10, 0}; 

    printf("waiting for fifo input\n");
    int res = select(fd + 1, &set, NULL, NULL, &timeout);

    if (res > 0) {
        char buf[100];
        int len = read(fd, buf, 100);
        buf[len] = '\0';
        printf("fifo received: %s\n", buf);
    } else {
        printf("timeout no input in fifo.\n");
    }

    close(fd);
    return 0;
}

// waiting for fifo input
// timeout no input in fifo.
// h1n1cov@pisces-cetus:~/SS_handson2$ echo "hello fifo" > myfifo
// h1n1cov@pisces-cetus:~/SS_handson2$ ./a.out 
// waiting for fifo input
// fifo received: hello fifo