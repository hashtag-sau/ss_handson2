/*
============================================================================
Name : .c
Author : Saurabh Dubey
Description :18. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
Date: 20th sep, 2024.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>

int main(){
    int pipefd[2];
    pipe(pipefd);

    if(fork()){
        close(pipefd[1]);
        dup2(pipefd[0],0);
        execlp("wc","wc",NULL);
    }
    else{
        int pipefd2[2];
        pipe(pipefd2);
        if(fork()){
            close(pipefd2[1]);
            close(pipefd[0]);
            dup2(pipefd[1],1); // grep will write its output to pipe1 via stdout
            dup2(pipefd2[0],0); // grep will read from pipe2 read end via stdin;
            execlp("grep","grep","^d",NULL);
        }
        else{
            close(pipefd[0]);
            close(pipefd[1]);
            close(pipefd2[0]);

            dup2(pipefd2[1],1);
            execlp("ls","ls","-l",NULL);
        }

    }

}

      //0       0       0