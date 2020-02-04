#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main(){
    int pipe_fd[2];
    if(pipe(pipe_fd)==-1){
        perror("pipe");
    }else{
        pid_t PID;

    switch(PID = fork()){
        case -1:
        perror("fork");
        exit(0);
        break;

        case 0:
        close(pipe_fd[1]);
        sleep(2);
        char buf[50];
        read(pipe_fd[0],buf,sizeof(buf));
        printf("This is child process.Received message is %s \n",buf);
        exit(0);
        break;

        default:
        
        close(pipe_fd[0]);
        char msg[] = "Message from Parent";
        write(pipe_fd[1],msg, sizeof(msg));
        exit(0);

        break;
    }
    }
    return(0);
}