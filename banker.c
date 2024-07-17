#include <stdio.h>

struct process
{
    int allocation[3]; // Resources currently allocated to this process
    int max[3];        // Maximum resources this process may need
    int need[3];       // Resources still needed by this process
    int finish;        // Process completion status
} p[10];

int main()
{
    int n, i, j, avail[3], work[3], flag, count = 0, sequence[10], k = 0;

    // Read number of processes
    printf("\nEnter the number of process: ");
    scanf("%d", &n);

    // Read allocated and maximum resources for each process
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the %dth process allocated resources: ", i);
        scanf("%d%d%d", &p[i].allocation[0], &p[i].allocation[1], &p[i].allocation[2]);

        printf("\nEnter the %dth process maximum resources: ", i);
        scanf("%d%d%d", &p[i].max[0], &p[i].max[1], &p[i].max[2]);

        p[i].finish = 0; // Initialize finish to 0 (false)
        // Calculate need as max - allocation
        p[i].need[0] = p[i].max[0] - p[i].allocation[0];
        p[i].need[1] = p[i].max[1] - p[i].allocation[1];
        p[i].need[2] = p[i].max[2] - p[i].allocation[2];
    }

    // Read available resources
    printf("\nEnter the available vector: ");
    scanf("%d%d%d", &avail[0], &avail[1], &avail[2]);

    // Initialize work with available resources
    for (i = 0; i < 3; i++)
        work[i] = avail[i];

    // Check for safe sequence
    while (count != n)
    {
        count = 0;
        for (i = 0; i < n; i++)
        {
            flag = 1;
            if (p[i].finish == 0)
            { // If process is not finished
                if (p[i].need[0] <= work[0] && p[i].need[1] <= work[1] && p[i].need[2] <= work[2])
                {
                    // If resources needed are less than or equal to work
                    for (j = 0; j < 3; j++)
                        work[j] += p[i].allocation[j]; // Add allocated resources to work
                    p[i].finish = 1;                   // Mark process as finished
                    sequence[k++] = i;                 // Add process to safe sequence
                    flag = 0;
                }
            }
            if (flag == 1)
                count++;
        }
    }

    // Check if all processes are finished
    count = 0;
    for (i = 0; i < n; i++)
        if (p[i].finish == 1)
            count++;

    // Print the safe sequence
    printf("\n The safe sequence is:\t");
    if (count == n)
    {
        for (i = 0; i < k; i++)
            printf("%d\t", sequence[i]);
    }
    else
    {
        printf("SYSTEM IS NOT IN A SAFE STATE \n\n");
    }

    return 0;
}
