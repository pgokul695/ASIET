#include <stdio.h>
#include <string.h>


typedef struct process {
    int pid;
    char pname[10];
    int at;
    int bt;
    int ct;
    int tt;
    int wt;
    int rt;
} fcfs;

void getprocess(fcfs p[100], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter the %d Process PID: ", i + 1);
        scanf("%d", &p[i].pid);
        printf("Enter the %d Process Name: ", i + 1);
        scanf("%s", p[i].pname);
        printf("Enter the %d Process Arrival time: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter the %d Process Burst time: ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].ct = 0;
        p[i].rt = p[i].bt;
    }
}
void sort(fcfs p[100], int n){
	int i,j;
	fcfs temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(p[j].at>p[j+1].at){
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}

}
				
	

void tt(fcfs p[100], int n) {
    int i;
    for (i = 0; i < n; i++) {
        p[i].tt = p[i].ct - p[i].at;
    }
}

void wt(fcfs p[100], int n) {
    int i;
    for (i = 0; i < n; i++) {
        p[i].wt = p[i].tt - p[i].bt;
    }
}

int complete(fcfs p[100], int n, fcfs c[100], int tq) {
    int i, t = 0, comp = 0, ind = 0;
    int remaining = n; 

    while (comp < n) {
        int executed = 0;
        
        for (i = 0; i < n; i++) {
            if (p[i].at <= t && p[i].rt > 0) {
                executed = 1;
                if (p[i].rt > tq) {
                    c[t] = p[i];
                    p[i].rt -= tq;
                    t += tq;
                } else {
                    c[t] = p[i];
                    t += p[i].rt;
                    p[i].rt = 0;
                    p[i].ct = t;
                    comp++;
                }
            }
        }

        if (!executed) {
            strcpy(c[t].pname, "IDLE");
            c[t].pid==-1;
            t++;
        }
    }
    return t;
}

/*int complete(fcfs p[100], int n, fcfs c[100], int tq) {
    int q[100];    
    int f = 0, r = 0;
    int t = 0, comp = 0;  
    int remaining = n;

    while (comp < n) {
        int executed = 0;  

        for (int i = 0; i < n; i++) {
            if (p[i].at <= t && p[i].rt > 0) {
                q[r++] = i;  
            }
        }
            if(f<r){
            	int i = q[f++];
            	if (p[i].rt > 0) {
                executed = 1;
                //printf("%d%d",p[i].pid,i);
                if (p[i].rt > tq) {
                    c[t] = p[i];
                    p[i].rt -= tq;
                    t += tq;
                    q[r++]=i;
                } else {
                    c[t] = p[i];
                    t += p[i].rt;
                    p[i].rt = 0;
                    p[i].ct = t;
                    comp++;
                }
            }
            //printf("%d\t%d",t,c[t].pid);

        if (!executed) {
            strcpy(c[t].pname, "IDLE");
            c[t].pid=-1;
            t++;
        }
      }
      else{
      	t++;
      }
    return t;
}
}
*/
					
		
				



void print(fcfs p[100], int n) {
    int i;
    printf("\nPID\tName\tAT\tBT\tCT\tTT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].pname, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);
    }
}

void gantt(fcfs c[100], int t) {
    int i;

    printf("\nGantt Chart:\n");

    printf("| %s ", c[0].pname);
    for (i = 1; i < t; i++) {
        if (c[i].pid != c[i - 1].pid ) {
            printf("| %s ", c[i].pname);
        }
    }
    printf("|\n");

    printf("0");
    for (i = 1; i < t; i++) {
        if (c[i].pid != c[i - 1].pid) {
            printf("    %d", i);
        }
    }
    printf("    %d\n", t);
}


int main() {
    fcfs p[100], c[100];
    int n, total_time, i,tq;
    float avgtt = 0, avgwt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter details of processes\n");
    getprocess(p, n);
    
    printf("Enter time quantum: ");
    scanf("%d",&tq);
	sort(p,n);
    total_time = complete(p, n, c,tq);
    tt(p, n);
    wt(p, n); 

    gantt(c, total_time);
    print(p, n);

    for (i = 0; i < n; i++) {
        avgtt += p[i].tt;
        avgwt += p[i].wt;
    }

    printf("Average Turnaround Time: %.2f\n", (avgtt / n));
    printf("Average Waiting Time: %.2f\n", (avgwt / n));

    return 0;
}

