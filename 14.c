/*
============================================================================
Name : .c
Author : Saurabh Dubey
Description :14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 20th sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>


int main(){
    int pipefd[2]; // first one to read and second one to write
    char buf[100];
    pipe(pipefd); //creates a pipe and give its fd in pipefd;

    int j = write(pipefd[1], "Hello world\n", 13);
    read(pipefd[0], buf, j);
    printf("From pipe: %s\n", buf);

}
// From pipe: Hello world
