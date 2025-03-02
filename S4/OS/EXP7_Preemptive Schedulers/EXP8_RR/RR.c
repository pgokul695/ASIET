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
    int q[100];    
    int f = 0, r = 0;
    int t = 0, comp = 0;
    int visited[100] = {0};

    for (int i = 0; i < n; i++) {
        if (p[i].at == 0) {
            q[r++] = i;
            visited[i] = 1;
        }
    }

    while (comp < n) {
        if (f == r) { 
            strcpy(c[t].pname, "IDLE");
            c[t].pid = -1;
            t++;
            continue;
        }

        int i = q[f++];
        int exec_time;

        if (p[i].rt > tq) {
            exec_time = tq;
        } else {
            exec_time = p[i].rt;
        }

        c[t] = p[i];
        t += exec_time;
        p[i].rt -= exec_time;

        for (int j = 0; j < n; j++) {
            if (visited[j] == 0 && p[j].at <= t) {
                q[r++] = j;
                visited[j] = 1;
            }
        }

        if (p[i].rt > 0) {
            q[r++] = i;
        } else {
            p[i].ct = t;
            comp++;
        }
    }
    return t;
}

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
        if (c[i].pid != c[i - 1].pid || strcmp(c[i].pname, "IDLE") == 0) {
            printf("| %s ", c[i].pname);
        }
    }
    printf("|\n");

    printf("0");
    for (i = 1; i < t; i++) {
        if (c[i].pid != c[i - 1].pid || strcmp(c[i].pname, "IDLE") == 0) {
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
    
    printf("Enter time quantum");
    scanf("%d",&tq);

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

