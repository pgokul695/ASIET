#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(){
	int a,temp;
	pid_t p;
	while(true){
		printf("System calls\n");
		printf("Menu\n");
		printf("1.fork\n");
		printf("2.exec\n");
		printf("3.get pid\n");
		printf("4.wait\n");
		printf("5.close\n");
		printf("6.stat\n");
		printf("7.opendir\n");
		printf("8.readdir\n");
		printf("9.exit\n");
		scanf("%d",&a);
		if(a==1){
			p= fork();
			if(p!=-1){
				printf("New process created pid= %d",p);
			}
			else{
				printf("Error in creating process");
			}
		}
		else if(a==2){
			//exec();
		}
		else if(a==3){
			printf("PID of currently executing process %d",getpid());
		}
		else if(a==4){
			wait(NULL);
			printf("Child process has been terminated");
		}
		else if(a==5){
			//close();
		}
		else if(a==6){
			//stat();
		}
		else if(a==7){
			//opendir();
		}
		else if(a==8){
			//readdir();
		}
		else if(a==9){
			printf("Exiting......");
			exit(0);
		}
		else{
			printf("Invalid option");
		}
	}
}
		
		
