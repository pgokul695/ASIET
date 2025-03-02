#include<stdio.h>
int main()
{
	int n,at[10],bt[10],temp[10],ct[10],wt[10],i,j,time=0,count=0,tat[10],smallest,pr[10];
	float avg_tat=0,avg_wt=0,end=0;
	printf("Enter the number of process:");
	scanf("%d",&n);
	printf("Enter the Process Details\n");
	for(i=0;i<n;i++){
		printf("Enter the values for process%d:\n",i+1);
		printf("Arrival Time: ");
		scanf("%d",&at[i]);
		printf("Burst Time: ");
		scanf("%d",&bt[i]);
		printf("Priority: ");
		scanf("%d",&pr[i]);
		temp[i]=bt[i];
	}
	pr[9]=1e9;
	for(time=0;count!=n;time++){
		smallest=9;
	for(i=0;i<n;i++){
		if(at[i]<=time&&pr[i]<pr[smallest]&&bt[i]>0){
			smallest=i;
		}
	}
		if(smallest!=9){
			bt[smallest]--;
			if(bt[smallest]==0)
			{
				count++;
				end=time+1;
				ct[smallest]=end;
				tat[smallest]=end-at[smallest];
				wt[smallest]=end-at[smallest]-temp[smallest];
			}
		}
	}
	printf("______________________________________________________________________________________________\n");
	printf("|\tPID\t|\tAT\t|\tBT\t|\tCT\t|\tTT\t|\tWT\t|\n");
	for(i=0;i<n;i++){
		printf("|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",i+1,at[i],temp[i],ct[i],tat[i],wt[i]);
	}
	printf("______________________________________________________________________________________________\n");
	for(i=0;i<n;i++){
		avg_tat+=tat[i];
		avg_wt+=wt[i];
	}
	printf("the average turn around time is:%4f\n",avg_tat/n);
	printf("the average waiting time is:%4f\n",avg_wt/n);
}
