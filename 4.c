#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/time.h>

unsigned long long rdtsc(){
    unsigned long long dst;
    __asm__ __volatile__("rdtsc":"=A"(dst));
    return dst;
}

int main(){
    long long int start, end;
    start = rdtsc();
    
    for(int i = 0 ; i < 100; i++) getppid();

    end = rdtsc();

    printf("Timestamp Counter Start: %llu\n", start);
    printf("Timestamp Counter End: %llu\n", end);
    printf("Elapsed TSC: %llu\n", end - start);

}


// Timestamp Counter Start: 3301355539
// Timestamp Counter End: 3301436819
// Elapsed TSC: 81280
// h1n1cov@pisces-cetus:~/SS_handson2$ ./a.out 
// Timestamp Counter Start: 4215102497
// Timestamp Counter End: 4215189974
// Elapsed TSC: 87477
// h1n1cov@pisces-cetus:~/SS_handson2$ ./a.out 
// Timestamp Counter Start: 45344344
// Timestamp Counter End: 45423498
// Elapsed TSC: 79154