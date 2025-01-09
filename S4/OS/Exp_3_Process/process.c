#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	char c;
	pid_t p;
	printf("currently executing process %d \n",getpid());
	printf("Create a new process in linux [Y/N]");
	scanf("%c",&c);
	if(c=='Y'||c=='y'){
		printf("A child process is created\n");
		p=fork();
		if(p!=-1){
			printf("Pid of currently executing process %d \n",getpid());
		}
		else{
			printf("FAILURE In creating a child process\nExiting...\n");
			return 0;
		}
	}
	else{
		printf("No New processes created, Exting.......\n");
		return 0;
	}
		
}
		
		
	

