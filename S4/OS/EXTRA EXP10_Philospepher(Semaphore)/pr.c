#include <stdio.h>
#include <stdlib.h>

void wait(int *s) {
    (*s)--; 
}


void signal(int *s) {
    (*s)++;
}

void start_eat(int id,int s[5],int stat[5]){
	int i;
	if(stat[id]){
		printf("The Philosepher %d is already eating\n",id);
	}
	else if(s[id]&&s[(id+1)%5]){
		printf("The Philosepher %d started eating\n",id);
		wait(&s[id]);
		wait(&s[(id+1)%5]);
		stat[id]=1;
	}
	else{
		printf("Chopstick Unavailable:Cannot start eating\n");
		printf("Philosepher %d is Thinking\n",id);
	}
	printf("Currently used Chopsticks [1-Used, 0-Unused]\n ");
   	for (int i = 0; i < 5; i++) {
       		printf("%d ", !s[i]);
   	 }
    	 printf("\nStatus of Philosephers [1-Eating, 0-Thinking]\n");
    	 for (int i = 0; i < 5; i++) {
       		printf("%d ", stat[i]);
   	 }
   	 printf("\n");
}

void stop_eat(int id,int s[5],int stat[5]){
	int i;
	if(!stat[id]){
		printf("The Philosepher %d is already Thinking\n",id);
	}
	else{
		printf("Philosepher Stopped Eating\n");
		signal(&s[id]);
		signal(&s[(id+1)%5]);
		stat[i]=0;
		printf("The Philosepher %d started Thinking\n",id);
	}
	printf("Currently used Chopsticks [1-Used, 0-Unused]\n");
   	for (int i = 0; i < 5; i++) {
       		printf("%d ", !s[i]);
    	}
    	printf("\nStatus of Philosephers [1-Eating, 0-Thinking]\n");
    	 	for (int i = 0; i < 5; i++) {
       			printf("%d ", stat[i]);
   	 	}
   	printf("\n");
}

void main(){
	int id,choice;
	int stat[5]={0};
	int s[5]={1,1,1,1,1};
	printf("Thinking Philosephers Problem\n");
	
    while (1) {
    	printf("Enter Philosepher ID[0-4](Enter -1 to exit)::\t");
    	scanf("%d",&id);
    	if(id==-1){
    		exit(0);
    	}
    	
        printf("MENU\n");
        printf("1. Start eating\n");
        printf("2. Stop Eating\n");
        printf("3. Exit\n");
        printf("Choose an option [1-3]: ");
        scanf("%d", &choice);

        if (choice == 1) {
            start_eat(id,s,stat);
        } else if (choice == 2) {
            stop_eat(id,s,stat);
        } else if (choice == 3) {
            printf("Exiting...\n");
            exit(0);
        } else {
            printf("Invalid choice, enter an option from [1-3]\n");
        }
    }
}
		
		
	
	
	
	
