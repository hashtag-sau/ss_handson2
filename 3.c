/*
============================================================================
Name : .c
Author : Saurabh Dubey
Description :3. Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 20th sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <sys/resource.h>

int main() {
    struct rlimit l;

    getrlimit(RLIMIT_NOFILE, &l);
    printf("current limits for maximum number of open files:\n");
    printf("current (soft) limit: %lu\n", l.rlim_cur);
    printf("max hard limit: %lu\n\n", l.rlim_max);

    l.rlim_cur = 1024; // setting cur means, setting soft limit
    l.rlim_max = 10000;
    setrlimit(RLIMIT_NOFILE, &l);
 
    getrlimit(RLIMIT_NOFILE, &l);
    printf("new limits for maximum number of open files:\n");
    printf("current (soft) limit: %lu\n", l.rlim_cur);
    printf("max hard limit: %lu\n", l.rlim_max);

    return 0;
}

// Current limits for maximum number of open files:
// current (soft) limit: 1048576
// max hard limit: 1048576

// New limits for maximum number of open files:
// current (soft) limit: 1024
// max hard limit: 1048576
// h1n1cov@pisces-cetus:~/SS_handson2$ gcc 3.c 
// h1n1cov@pisces-cetus:~/SS_handson2$ ./a.out 
// Current limits for maximum number of open files:
// current (soft) limit: 1048576
// max hard limit: 1048576

// New limits for maximum number of open files:
// current (soft) limit: 1024
// max hard limit: 10000

