/*
============================================================================
Name : .c
Author : Saurabh Dubey
Description :16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 20th sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(){
    int pipefd_PtoC[2];
    int pipefd_CtoP[2];
    pipe(pipefd_PtoC);
    pipe(pipefd_CtoP);

    if(fork()){ //parent
        char buf[100];
        close(pipefd_PtoC[0]); //read pipe close for pipe P to C
        close(pipefd_CtoP[1]); //closing write end of child to parent pipe

        write(pipefd_PtoC[1],"hello child\n",13);

        read(pipefd_CtoP[0],buf, 100);
        printf("message from child: %s\n",buf);    
    }
    else{
        char buf[100];
        close(pipefd_CtoP[0]); 
        close(pipefd_PtoC[1]); 
        
        write(pipefd_CtoP[1],"hello parent\n",13);

        read(pipefd_PtoC[0],buf,100);
        printf("message from parent: %s \n",buf); 
    }

}
//even though fork doesn't guarantee order of execution of parent and child then also our printed correctly because of reason below

//If a process attempts to read from an empty pipe, then read(2) will block until data is available.
// If a process attempts to write to a full pipe (see below), 
//then write(2) blocks until sufficient data has been read from the pipe to allow the write to complete

//output
// message from parent: hello child
 
// message from child: hello parent
