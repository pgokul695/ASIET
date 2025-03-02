#include<stdio.h>
int main(){
	int p[20],bt[20],wt[20],tt[20],n,i;
	float avg_wt=0.0,avg_tt=0.0;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter the  and process id:\n");
	for(i=0;i<n;i++){
		printf("For process %d: ",i+1);
		scanf("%d",&p[i]);
	}
	printf("Enter the burst time:\n");
	for(i=0;i<n;i++){
		printf("For process P%d: ",p[i]);
		scanf("%d",&bt[i]);
	}
	wt[0]=0;
	for(i=0;i<n;i++){
		wt[i]=wt[i-1]+bt[i-1];
		avg_wt+=wt[i];
	}
	avg_wt=avg_wt/n;
	for(i=0;i<n;i++){
		tt[i]=wt[i]+bt[i];
		avg_tt+=tt[i];
	}
	avg_tt=avg_tt/n;
	printf("_________________________________________________________________\n");
	printf("|\tPID\t|\tBT\t|\tWT\t|\tTT\t|\n");
	for(i=0;i<n;i++){
		printf("|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",p[i],bt[i],wt[i],tt[i]);
	}
	printf("_________________________________________________________________\n");
	printf("GANTT CHART");
	printf("\n_________________________________________________________________\n");
	for(i=0;i<n;i++)
	{
		printf("|P%d\t|",p[i]);
	}
	printf("\n_________________________________________________________________\n");
	printf("%d\t",wt[0]);
	for(i=0;i<n;i++){
		printf("%d\t",tt[i]);
	}
	printf("\nThe average waiting time is:%4f\n",avg_wt);
	printf("The average turn around time is:%4f\n",avg_tt);
}
