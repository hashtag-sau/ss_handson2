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
        close(pipefd[0]);//cloes read end

        dup2(pipefd[1],1);//fd 1 will now point to what pipefd[1] was pointing to i.e in our case the pipe we created

        execlp("ls","ls","-l",NULL); //execlp read writes on std by default i.e on fd 0, 1;
    }
    else{
        close(pipefd[1]); //close write end

        dup2(pipefd[0],0);//redirect stdin to pipe read end;

        execlp("wc","wc",NULL);

    }
}
  //33     290    1705