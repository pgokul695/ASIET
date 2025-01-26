#include<stdio.h>
#include<string.h>

typedef struct process{
	int pid;
	char pname[10];
	int at;
	int bt;
	int ct;
	int tt;
	int wt;
}fcfs;

void getprocess(fcfs p[100],int n)
{
	 int i;
	 for(i=0;i<n;i++){
	 	printf("Enter the %d Process PID: ",i+1);
	 	scanf("%d",&p[i].pid);
	 	printf("Enter the %d Process Name: ",i+1);
	 	scanf("%s",p[i].pname);
	 	printf("Enter the %d Process Arrival time: ",i+1);
	 	scanf("%d",&p[i].at);
	 	printf("Enter the %d Process Burst time: ",i+1);
	 	scanf("%d",&p[i].bt);
	 }
}

void sort(fcfs p[100],int n)
{
	int i,j; 
	fcfs key;
	for (i = 1; i < n; i++) {
		key = p[i];
		j = i - 1;
		while (j >= 0 && p[j].at > key.at) {
			p[j + 1] = p[j]; 
			j--;
		}
		p[j + 1] = key;
	}
}

void complete(fcfs p[100], int n){
	int i,t=0;
	for(i=0;i<n;i++){
		if(t < p[i].at){
    			t = p[i].at;
		}
		t += p[i].bt;
		p[i].ct = t;
	}
}
void tt(fcfs p[100],int n){
	int i;
	for(i=0;i<n;i++){
		p[i].tt=p[i].ct-p[i].at;
	}
}
void wt(fcfs p[100],int n){
	int i;
	for(i=0;i<n;i++){
		p[i].wt=p[i].tt-p[i].bt;
	}
}
void print(fcfs p[100], int n){
	int i;
	printf("\nPID\tName\tAT\tBT\tCT\tTT\tWT\n");
	for (i = 0; i < n; i++) {
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].pname, p[i].at, p[i].bt, p[i].ct, p[i].tt,p[i].wt);
	}
}
void gantt(fcfs p[100], int n){
    int i, t = 0;
    printf("\nGantt Chart:\n");

    for (i = 0; i < n; i++) {
        if (t < p[i].at) {
            printf("| IDLE ");
            t = p[i].at;
        }
        printf("| %s ", p[i].pname);
        t += p[i].bt;
    }
    printf("|\n");

    printf("0");
    t = 0;
    for (i = 0; i < n; i++) {
        if (t < p[i].at) {
            t = p[i].at;
            printf("       %d", t);
        }
        t += p[i].bt;
        printf("    %d", t);
    }
    printf("\n");
}


int main(){
	fcfs p[100];
	int n,i;
	float avgtt=0,avgwt=0;
	printf("Enter the number of processes");
	scanf("%d",&n);
	printf("Enter details of processes\n");
	getprocess(p,n);
	sort(p,n);
	complete(p,n);
	tt(p,n);
	wt(p,n);
	gantt(p,n);
	print(p,n);
	for(i=0;i<n;i++){
		avgtt+=p[i].tt;
		avgwt+=avgwt+p[i].wt;
	}
	printf("Average Turn around time is: %f\n",(avgtt/n));
	printf("Average Waiting time is: %f\n",(avgwt/n));
	return 0;
}

