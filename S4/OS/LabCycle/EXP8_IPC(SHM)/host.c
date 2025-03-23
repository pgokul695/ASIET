#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){
	int shid,nt,i;
	void *shmp;
	char buffer[100];
	
	int avail;
	shid=shmget(01234,sizeof(shmp),0644|IPC_CREAT);// create a shared memory area
	if(shid==-1){
		printf("Failed to create shared memory pool aborting process\n");
		return 1;
	}
	
	shmp=shmat(shid,NULL,0);//atatch to the shared memory
	if(shmp==(void *)-1){
		printf("Failed to attach to shared memory,process terminating\n");
		return 1;
	}
	//writing to shared memory
	printf("Enter the data to be written:\t");
	scanf("%s",buffer);
	strcpy(shmp,buffer);

	printf("Writing Process:Writing finished\n");
	
	if(shmdt(shmp)==-1){//detaching from shared memory
		printf("Failed to detatch from Shared memory, process terminating\n");
		return 1;
	}

	printf("Writing process Completed\n");
	return 0;
}

	
	
		
		
		
	
