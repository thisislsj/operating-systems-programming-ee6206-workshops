#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/stat.h>
#include <pthread.h>

void * thread_f1(void * arguments);
void * thread_f2(void * arguments);
int glb_var=0;

int main(){
    pthread_t tid1, tid2;
    int count = 1000000;
    pthread_create(&tid1,NULL,thread_f1,(void *)&count);
    pthread_create(&tid2, NULL,thread_f2,(void *)&count);

    //This is main thread
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    printf("\nThe final value of global variable is %d", glb_var);

    return(0);

}

void * thread_f1(void * arguments){
    int x= *(int *)arguments;
    for(int i=0;i<x;i++){
        glb_var++;
    }
    pthread_exit(NULL);
}

