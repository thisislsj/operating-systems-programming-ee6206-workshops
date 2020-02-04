#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int data_v=100;

int main(){
    int stack_v=1000;
    int *heap_v = malloc(4);
    *heap_v=10000;

    pid_t PID;

    switch(PID = fork()){
        case -1:
        perror("fork");
        exit(PID);
        break;

        case 0:
        stack_v=2000;
        data_v=20;
        *heap_v=20000;
        break;

        default:
        sleep(2);
        break;
    }

    //both parent and child processes will come here
    printf("\n This %s process with %d. data_v is %d stack_v is %d heap_v is %d,  \n", ((PID==0) ? "child": "parent"), getpid() data_v,stack_v,*heap_v);
    return(0);
}