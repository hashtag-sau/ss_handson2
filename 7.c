/*
============================================================================
Name : 7.c
Author : Saurabh Dubey
Description :7. Write a simple program to print the created thread ids.
Date: 20th sep, 2024.
============================================================================
*/
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

void *thread_func(void *arg){
    int no = *((int *)arg);
    printf("hi i am thread %d ",no);
    printf("my thread id is %lu \n", pthread_self());//this function reaturns thread id of itself
    return NULL;
}


int main(){
    pthread_t t1,t2,t3;
    int one = 1, two = 2, three = 3;
    pthread_create(&t1,NULL,thread_func,&one); //first param for address of thread, second for setting attributes like stack size, scheduling policy etc.
    //third is func name //fourth is argument to fucntion in third.

    pthread_create(&t2,NULL,thread_func,&two);
    pthread_create(&t3,NULL,thread_func,&three);

    pthread_join(t1,  NULL);
    pthread_join(t2,  NULL);
    pthread_join(t3,  NULL);

    return 0;
}
// hi i am thread 2 my thread id is 140118802056768 
// hi i am thread 3 my thread id is 140118793664064 
// hi i am thread 1 my thread id is 140118810449472 

