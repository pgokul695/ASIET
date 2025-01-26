#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int status,pid,child_pid;
	pid=fork();
	if(pid==-1)
	{
		printf("Child process creation failed\n");
		return -1;
	}
	else if(pid==0){
		printf("Inside the child process with PID:%d\n",getpid());
		execlp("/bin/date","date",NULL);
		return 0;
	}
	else{
		child_pid=wait(&status);
		printf("\nInside parant process with PID:%d\n",getpid());
		printf("Child process creation succesful\n");
		return 0;
	}
}


