#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd1 = open("./my_fifo2", O_RDONLY);
    int fd2 = open("./my_fifo", O_WRONLY);

    write(fd2,"hello!! from 21a.c", 19);

    char buf[100];
    read(fd1, buf, 100);
    printf("in 21a.c message: %s", buf);


return 0;
}