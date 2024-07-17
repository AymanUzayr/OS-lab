#include <stdio.h>

struct process {
    int burst;  // Burst time (execution time) of the process
    int wait;   // Waiting time of the process
    int comp;   // Time the process has been completed (used for tracking progress)
    int f;      // Flag to check if the process is finished
} p[20] = {0, 0};  // Initialize the array of process structures with zero values

int main() {
    int n, i, j, totalwait = 0, totalturn = 0, quantum, flag = 1, time = 0;

    // Read number of processes
    printf("\nEnter The No Of Process :");
    scanf("%d", &n);

    // Read the time quantum
    printf("\nEnter The Quantum time (in ms) :");
    scanf("%d", &quantum);

    // Read burst times for each process
    for (i = 0; i < n; i++) {
        printf("Enter The Burst Time (in ms) For Process #%2d :", i + 1);
        scanf("%d", &p[i].burst);
        p[i].f = 1;  // Initialize flag to 1 (indicating the process is not finished)
    }

    // Print header for order of execution
    printf("\nOrder Of Execution \n");
    printf("\nProcess Starting Ending Remaining");
    printf("\n\t\tTime \tTime \t Time");

    // Round Robin scheduling
    while (flag == 1) {
        flag = 0;
        for (i = 0; i < n; i++) {
            if (p[i].f == 1) {  // If process is not finished
                flag = 1;
                j = quantum;

                if ((p[i].burst - p[i].comp) > quantum) {
                    p[i].comp += quantum;
                } else {
                    p[i].wait = time - p[i].comp;
                    j = p[i].burst - p[i].comp;
                    p[i].comp = p[i].burst;
                    p[i].f = 0;
                }

                // Print the details of the current execution
                printf("\nprocess # %-3d %-10d %-10d %-10d", i + 1, time, time + j, p[i].burst - p[i].comp);
                time += j;
            }
        }
    }

    // Print header for process details
    printf("\n\n------------------");
    printf("\nProcess \t Waiting Time TurnAround Time ");

    // Calculate total waiting time and turnaround time
    for (i = 0; i < n; i++) {
        printf("\nProcess # %-12d%-15d%-15d", i + 1, p[i].wait, p[i].wait + p[i].burst);
        totalwait += p[i].wait;
        totalturn += p[i].wait + p[i].burst;
    }

    // Print average waiting time and turnaround time
    printf("\n\nAverage\n------------------ ");
    printf("\nWaiting Time: %fms", totalwait / (float)n);
    printf("\nTurnAround Time : %fms\n\n", totalturn / (float)n);

    return 0;
}
