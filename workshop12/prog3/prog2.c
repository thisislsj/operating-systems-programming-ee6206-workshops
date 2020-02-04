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

char * name = "/sema";
sem_t * sem1;

int main(){
    sem1=sem_open(name1,O_CREAT,0666,1 );
    pthread_t tid1,tid2,tid3;

    int count =10000000;
    pthread_t tid1, tid2;
    
    pthread_create(&tid1,NULL,thread_f1,NULL);
    pthread_create(&tid2,NULL,thread_f2,NULL);
    pthread_create(&tid3,NULL,thread_f3,NULL);


    //This is main thread
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    return(0);
}

void * thread_f1(void * arguments){
    print("Hello");
    pthread_exit(NULL);
}

void * thread_f2(void * arguments){
    sem_wait(sem1);
    printf("my name is ");
    sem_post(sem2);
    pthread_exit(NULL);
}

void * thread_f3(void * arguments){
    print("Hello");
    pthread_exit(NULL);
}



