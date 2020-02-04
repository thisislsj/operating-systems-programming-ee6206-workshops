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
pthread_mutex_t mut1=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1=PTHREAD_COND_INITIALIZER
pthread_cond_t cond2=PTHREAD_COND_INITIALIZER

int main(){
    int count =0;
    pthread_t tid1, tid2;
    
    pthread_create(&tid1,NULL,thread_f1,(void *)&count);
    pthread_create(&tid2, NULL,thread_f2,(void *)&count);

    //This is main thread
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    

    return(0);

}

void * thread_f1(void * arguments){
    int x= *(int *)arguments;
    for(int i=0;i<x;i++){
        pthread_mutex_lock(&mutid);
        for(int j=0;j<x;j++){
            printf("thread1\n");
        }
        glb_var++;
        pthread_mutex_unlock(&mut1); //unlocak the mutex to be used by any other thread
    }
    pthread_exit(NULL);
}
void * thread_f2(void * arguments){
    int x= *(int *)arguments;
    for(int i=0;i<x;i++){
        pthread_mutex_lock(&mut1);
        glb_var++;
        pthread_mutex_unlock(&mut1); //unlocak the mutex to be used by any other thread
    }
    pthread_exit(NULL);
}

