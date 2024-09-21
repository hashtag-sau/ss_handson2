/*
============================================================================
Name : 8.c
Author : Saurabh Dubey
Description : 8. Write a separate program using signal system call to catch the following signals.

Date: 20th sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handle_sigsegv(int signum){
    printf("you got seg fault!!! be careful!!\n"); 
}

int main(){
    signal(SIGSEGV,handle_sigsegv);
    int *a;
    int num;
    num = *(a+10);
    return 0;
}

// you got seg fault!!! be careful!!  //it ran infinite because no exit() was given in handler function
// you got seg fault!!! be careful!!
// you got seg fault!!! be careful!!
// you got seg fault!!! be careful!!
// you got seg fault!!! be careful!!
// ^C