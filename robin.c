#include <stdio.h>

int main() {
    int n, bt[10], wt[10], tat[10], rem_bt[10], pno[10];
    int i, j, quantum, t = 0, count = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the burst time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; // Copy burst times to remaining burst times
        pno[i] = i; // Assigning process numbers
    }

    printf("\nEnter the time quantum: ");
    scanf("%d", &quantum);

    while (1) {
        count = 0;
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                count++;
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    tat[i] = t;
                    rem_bt[i] = 0;
                }
            }
        }
        if (count == 0)
            break;
    }

    // Calculate average waiting time and average turnaround time
    for (i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;

    // Print the results
    printf("\nProcess No\tBurst Time\tWait Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", pno[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", avg_wt);
    printf("Average Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
