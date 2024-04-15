#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    printf("\n---------------------------------------\n\t     FCFS Scheduling\n---------------------------------------\n");
    int pn, at[20], bt[20], i, tat[20], com[20], wt[20], temp, j;
    float avg = 0, avg2 = 0, avgtat, avgwt;
    printf("\nEnter the number of processes for FCFS SCHEDULING: ");
    scanf("%d", &pn);
    printf("\nEnter the arrival times: ");
    for (i = 0; i < pn; i++)
        scanf("%d", &at[i]);
    printf("\nEnter the burst times: ");
    for (i = 0; i < pn; i++)
        scanf("%d", &bt[i]);
    printf("\n\n");
    for (i = 0; i < pn; i++) {
        for (j = i + 1; j < pn; j++) {
            if (at[i] > at[j]) {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    int idle_time = 0;
    com[0] = bt[0] + at[0];
    tat[0] = bt[0];
    wt[0] = 0;
    for (i = 1; i < pn; i++) {
        if (com[i - 1] < at[i]) {
            idle_time += at[i] - com[i - 1];
            com[i] = at[i] + bt[i];
        } else {
            com[i] = com[i - 1] + bt[i];
        }
        tat[i] = com[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    for (i = 0; i < pn; i++)
        avg += tat[i];

    avgtat = avg / pn;

    for (i = 0; i < pn; i++)
        avg2 += wt[i];

    avgwt = avg2 / pn;

    printf("pno\tat\tbt\tcom\ttat\twt\t\n");
    for (i = 0; i < pn; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], com[i], tat[i], wt[i]);
    }

    printf("AVGTAT= %f\nAWT= %f\nCPU Idle Time= %d\n", avgtat, avgwt, idle_time);

    // Print Gantt Chart
    printf("\nGantt Chart:\n");
    printf("|0");
    for (i = 0; i < pn; i++) {
        printf("-P%d-%d", i+1, com[i]);
    }
    printf("|");

    return 0;
}
