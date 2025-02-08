#include<stdio.h>
#include<string.h>

typedef struct process {
    int pid;
    char pname[10];
    int at;
    int bt;
    int ct;
    int tt;
    int wt;
    int pr;
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
        printf("Enter the %d process Priority [1-10 10 being the highest priority]:",i+1);
        scanf("%d", &p[i].pr);
        p[i].ct = 0; 
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

void complete(fcfs p[100], int n, fcfs c[100]) {//assuming higher number means higher priority
    int i, t = 0, comp = 0, max_pr, ind;

    while (comp < n) {
        max_pr = -1;//Minimum possible value  
        ind = -1;

        for (i = 0; i < n; i++) {//to find the highest priority job available
            if ((p[i].at <= t) && (p[i].ct == 0) && (p[i].pr > max_pr)) {
                max_pr = p[i].pr;
                ind = i;
            }
        }

        if (ind != -1) { //to mark the job as completed and add the ct to the job
            t += p[ind].bt;
            p[ind].ct = t;
            c[comp]=p[ind];//to append the completed task to completed list for gantt chart
            comp++;
            
        } else { //if no job found that is incomplete at time t, increment t by 1 
            t++;
            
        }
    }
}

void print(fcfs p[100], int n) {
    int i;
    printf("\nPID\tName\tAT\tBT\tCT\tTT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].pname, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);
    }
}
void gantt(fcfs p[100], int n) {
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

int main() {
    fcfs p[100],c[100];
    int n, i;
    float avgtt = 0, avgwt = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter details of processes\n");
    getprocess(p, n);
    complete(p, n, c);
    tt(p, n);
    wt(p, n);
    gantt(c, n);
    print(p, n);
    for (i = 0; i < n; i++) {
        avgtt += p[i].tt;
        avgwt += p[i].wt;
    }
    printf("Average Turn around time is: %f\n", (avgtt / n));
    printf("Average Waiting time is: %f\n", (avgwt / n));
    return 0;
}

