/*
============================================================================
Name : 15.c
Author : Saurabh Dubey
Description :15. Write a simple program to send some data from parent to the child process.
Date: 20th sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(){
    int pipefd[2];

    pipe(pipefd);
    if(fork()){//parent will write to pipe through pipefd[1]
        close(pipefd[0]);
        write(pipefd[1],"hello my child\n",16);
    }
    else{
        char buf[100];
        close(pipefd[1]);
        read(pipefd[0],buf,16);
        printf("message from parent is: %s", buf);
    }
}
//message from parent is: hello my child