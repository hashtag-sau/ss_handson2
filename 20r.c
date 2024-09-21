#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>

int main() {
    int fd;
    char buf[100];


    fd = open("my_fifo", O_RDONLY);


    read(fd, buf, 100);
    printf("recieved message from fifo pipe: %s",buf);
  
    close(fd);
    return 0;
}
//recieved message from fifo pipe: this a hello from writer