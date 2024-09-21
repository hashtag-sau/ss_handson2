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
#include<fcntl.h>

int main(){
    int pipefd[2];
    pipe(pipefd);

    if(fork()){//parent
        close(pipefd[0]);//cloes read end
        close(1);
        fcntl(pipefd[1],F_DUPFD,STDOUT_FILENO);//redirect stdout to pipe write end

        execlp("ls","ls","-l",NULL); //execlp read writes on std by default i.e on fd 0, 1;

    }
    else{
        close(pipefd[1]); //close write end
        close(0);

        fcntl(pipefd[0],F_DUPFD,STDIN_FILENO);//redirect stdin to pipe read end;

        execlp("wc","wc",NULL);

    }
}
     //33     290    1705