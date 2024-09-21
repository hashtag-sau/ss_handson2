/*
============================================================================
Name : .c
Author : Saurabh Dubey
Description :20. Write two programs so that both can communicate by FIFO -Use one way communication
Date: 20th sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>

int main() {
    int fd;
    char message[] = "this a hello from writer";


    fd = open("my_fifo", O_WRONLY);


    // Write messages to the FIFO
        write(fd, message, 25);
  
    close(fd);
    return 0;
}
