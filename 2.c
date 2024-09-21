/*
============================================================================
Name : 2.c
Author : Saurabh Dubey
Description :. Write a program to print the system resource limits. Use getrlimit system call.
Date: 20th sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main(){
    struct rlimit l;

    getrlimit(RLIMIT_FSIZE, &l);
    printf("For File size: \n");
    printf("current(soft) limit %lu\n", l.rlim_cur);
    printf("max hard limit %lu\n", l.rlim_max);

    getrlimit(RLIMIT_CPU, &l);
    printf("For CPU: \n");
    printf("current(soft) limit %lu\n", l.rlim_cur);
    printf("max hard limit %lu\n", l.rlim_max);

    getrlimit(RLIMIT_DATA, &l);
    printf("For data segment: \n");
    printf("current(soft) limit %lu\n", l.rlim_cur);
    printf("max hard limit %lu\n", l.rlim_max);

    getrlimit(RLIMIT_NOFILE, &l);
    printf("For maximum number of open files: \n");
    printf("current(soft) limit %lu\n", l.rlim_cur);
    printf("max hard limit %lu\n", l.rlim_max);

    getrlimit(RLIMIT_STACK, &l);
    printf("For stack size: \n");
    printf("current(soft) limit %lu\n", l.rlim_cur);
    printf("max hard limit %lu\n", l.rlim_max);

    getrlimit(RLIMIT_AS, &l);
    printf("For virtual memory size: \n");
    printf("current(soft) limit %lu\n", l.rlim_cur);
    printf("max hard limit %lu\n", l.rlim_max);


}

// For File size: 
// current(soft) limit 18446744073709551615
// max hard limit 18446744073709551615
// For CPU: 
// current(soft) limit 18446744073709551615
// max hard limit 18446744073709551615
// For data segment: 
// current(soft) limit 18446744073709551615
// max hard limit 18446744073709551615
// For maximum number of open files: 
// current(soft) limit 1048576
// max hard limit 1048576
// For stack size: 
// current(soft) limit 8388608
// max hard limit 18446744073709551615
// For virtual memory size: 
// current(soft) limit 18446744073709551615
// max hard limit 18446744073709551615

