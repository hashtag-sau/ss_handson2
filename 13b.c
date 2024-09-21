//part 2 of 13.c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    int pid;

    printf("Enter the pid of program to stop ");
    scanf("%d", &pid);

    kill(pid, SIGSTOP);
  

    printf("Sent SIGSTOP\n");
    return 0;
}
