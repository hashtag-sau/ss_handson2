/*
============================================================================
Name : 17.c
Author : Saurabh Dubey
Description :17. Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl
Date: 20th sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main(){
    int pipefd[2];
    pipe(pipefd);

    if(fork()){//parent
        close(1);
        close(pipefd[0]);//cloes read end

        dup(pipefd[1]);//redirect stdout to pipe write end

        execlp("ls","ls","-l",NULL); //execlp read writes on std by default i.e on fd 0, 1;
    }
    else{
        close(0);
        close(pipefd[1]); //close write end

        dup(pipefd[0]);//redirect stdin to pipe read end;

        execlp("wc","wc",NULL);

    }
}
//31     272    1597