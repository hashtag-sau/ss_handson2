/*
============================================================================
Name : 5.c
Author : Saurabh Dubey
Description : 5. Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 20th sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>
#include <limits.h>

int main() {
    struct rlimit limit;
    struct sysinfo sys_info;
//sysconf is library function whereas sysinfo is system call
//sysconf gives configuration information at run time
//sysinfo gives system info such as ram usage free ram etc.

    printf("Maximum length of the arguments to the exec family: %d\n", sysconf(_SC_ARG_MAX));

    getrlimit(RLIMIT_NPROC, &limit);
    printf("Maximum number of simultaneous processes per user id: %lu\n", (unsigned long)limit.rlim_max);

    printf("Number of clock ticks (jiffy) per second: %ld\n", sysconf(_SC_CLK_TCK));

    getrlimit(RLIMIT_NOFILE, &limit);
    printf("Maximum number of open files: %lu\n", (unsigned long)limit.rlim_max);

    printf("Size of a page: %ld bytes\n", sysconf(_SC_PAGESIZE));

    sysinfo(&sys_info);
    printf("Total number of pages in the physical memory: %ld\n", sys_info.totalram / sysconf(_SC_PAGESIZE));
    printf("Number of currently available pages in the physical memory: %ld\n", sys_info.freeram / sysconf(_SC_PAGESIZE));
   

    return 0;
}

// Maximum length of the arguments to the exec family: 2097152 bytes
// Maximum number of simultaneous processes per user id: 29807
// Number of clock ticks (jiffy) per second: 100
// Maximum number of open files: 1048576
// Size of a page: 4096 bytes
// Total number of pages in the physical memory: 1940825
// Number of currently available pages in the physical memory: 180929