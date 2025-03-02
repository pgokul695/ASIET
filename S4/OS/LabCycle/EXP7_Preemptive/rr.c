#include <stdio.h>

void main() {
    int i, j, n, qt, count = 0, time = 0, index = 0;
    int bt[20], bt_cp[20], p[20], ct[20], wt[20], tt[20];
    int gantt_process[100], gantt_time[100];
    float wt_avg = 0, tt_avg = 0;

    printf("Enter the number of Processes (Max 20): ");
    scanf("%d", &n);

    printf("Enter the Burst Time of Each Process:\n");
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("P%d : ", p[i]);
        scanf("%d", &bt[i]);
        bt_cp[i] = bt[i];
        ct[i] = 0;
    }

    printf("Enter the Time Slice: ");
    scanf("%d", &qt);

    while (count != n) {
        for (i = 0; i < n; i++) {
            if (bt_cp[i] == 0) {
                continue;
            }
            if (bt_cp[i] > qt) {
                gantt_process[index] = p[i];
                gantt_time[index] = time + qt;
                time += qt;
                bt_cp[i] -= qt;
            } else {
                gantt_process[index] = p[i];
                gantt_time[index] = time + bt_cp[i];
                time += bt_cp[i];
                bt_cp[i] = 0;
                ct[i] = time;
                count++;
            }
            index++;
        }
    }

    for (i = 0; i < n; i++) {
        tt[i] = ct[i];
        wt[i] = tt[i] - bt[i];
        wt_avg += wt[i];
        tt_avg += tt[i];
    }

    wt_avg /= n;
    tt_avg /= n;

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tt[i], ct[i]);
    }

    printf("\nAverage Waiting Time: %.2f", wt_avg);
    printf("\nAverage Turnaround Time: %.2f\n", tt_avg);

    printf("\nGantt Chart:\n");
    for (i = 0; i < index; i++) {
        printf("| P%d ", gantt_process[i]);
    }
    printf("|\n");
    printf("0");
    for (i = 0; i < index; i++) {
        printf("    %d", gantt_time[i]);
    }
    printf("\n");
}
