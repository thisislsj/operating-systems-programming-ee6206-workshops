#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <string.h>



struct msg
{
	long type;
	char text[20];

};


struct msg createMsg(long type,char text[]);


int main()
{
	
	key_t key_for_SM1 = ftok("file1.txt",22);//creating a key
    key_t key_for_SM2 = ftok("file1.txt",33);//creating a key

	int SMID1 = shmget(key_for_SM1,4096,IPC_CREAT|0666);//creating the SM1
    int SMID2 = shmget(key_for_SM1,4096,IPC_CREAT|0666);//creating the SM2

	int PID1;

	switch(PID1 = fork()){
		case -1 : // error 
			perror("Chiled1");
			exit(0);
			break;
		case  0 : // child C1
			getpid();
			int PID2;
			switch(PID2 = fork()){
			case -1 : // error 
				perror("Child2");
				exit(0);
				break;
			case  0 : // child C2
				getpid();
				
				exit(0);

				break;
				
			default	: // child C1
			
				getpid();
                char * shmptrc1a;
                char * shmptrc1b;
                shmptrc1a=(char *)shmat(SMID1,NULL,SHM_W|SHM_R);
                shmptrc1b=(char *)shmat(SMID1,NULL,SHM_W|SHM_R);
                strcpy(bufc1a, shmptrc1a);
                printf("C1 received: %s", shmptrc1a);
                char msgc1a[]="Response from C1";
                char msgc1b[]="Message from C1";
                strcpy(shmptrc1a,msgc1a);
                strcpy(shmptrc1b,msgc1b);
                printf("\n C1 sent: %s",shmptrc1a);
                printf("\n C1 sent: %s", shmptrc1b);
                waitpid(PID)
                break;
				
				exit(0);
			
			break;
		}
		default	: // Parent P1
				getpid();
                char msgp1[]="message from parentp1";
                char * shmptrp1;
                shmptrp1=(char *)shmat(SMID1,NULL,SHM_W| SHM_R);
                strcpy(shmptrp1,msgp1); //write in to shared memory
                printf("\n P1 sent: %", shmptrp1);
                sleep(0.001);
                char bufp1[50];
                strcpy(bufp1,shm)

				
				exit(0);

			
			break;
			
	
	}


	return 0;
}


struct msg createMsg(long type,char text[]){

struct msg newMsg;
newMsg.type = type;
strcpy(newMsg.text,text);

return newMsg;

}