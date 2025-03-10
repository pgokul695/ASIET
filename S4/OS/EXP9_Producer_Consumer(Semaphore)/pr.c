#include<stdio.h>
#include<stdlib.h>

void wait(int *s){
	*s--;
	printf("%d",*s);
}

void signal(int *s){
	*s++;
	printf("%d",*s);
}

void consumer(int *mutex,int buff[3], int *full, int *empty){
	
	if(*mutex&&(*full > 0)){
		wait(full);
		wait(mutex);
		printf("Consumer consumed an item\n");
		signal(empty);
		signal(mutex);
	}
	else if(!*mutex){
		printf("Mutex Lock cannot be aquired\n");
	}
	else{
		printf("The buffer is empty Nothing to consume\n");
		printf("%d",*full);	
	}
}
void producer(int *mutex,int buff[3], int *full, int *empty){
	printf("Producer produced an item\n");
	if(*mutex&&(*empty>0)){
		wait(empty);
		wait(mutex);
		printf("Producer added a item to buffer\n");
		signal(full);
		signal(mutex);
	}
	else if(!*mutex){
		printf("Mutex Lock cannot be aquired\n");
	}
	else{
		printf("The buffer is full Cannot add the item to buffer\n");	
	}
}

void main(){
	int mutex,full,empty,buff[3];
	mutex=1;
	empty=3;
	full=0;
	int choice;
	printf("Producer Consumer Problem\n");
	while(1){
		printf("MENU\n");
		printf("1.Consumer\n");
		printf("2.Producer\n");
		printf("3.Exit\n");
		printf("Choose an option [1-3]: ");
		scanf("%d",&choice);
		if(choice==1){
			consumer(&mutex,buff,&full,&empty);
		}
		else if(choice==2){
			producer(&mutex,buff,&full,&empty);
		}
		else if(choice==3){
			printf("Exiting...\n");
			exit(0);
		}
		else{
			printf("invalid choice enter a option from 1-3");
		}
	}
}
	


