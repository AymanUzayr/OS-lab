#include <stdio.h>

struct process
{
    int allocation[10];
    int max[3];
    int need[3];
    int finish;
} p[10];

int main()
{
    int i, j, n, avail[3], work[3], sequence[10], flag = 1, count = 0, k = 0;
    printf("Enter the no of process: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the %dth process allocated resources: ", i);
        scanf("%d%d%d", &p[i].allocation[0], &p[i].allocation[1], &p[i].allocation[2]);

        printf("\nEnter the %dth process maximum resources: ", i);
        scanf("%d%d%d", &p[i].max[0], &p[i].max[1], &p[i].max[2]);

        p[i].finish = 0;

        p[i].need[0] = p[i].max[0] - p[i].allocation[0];
        p[i].need[1] = p[i].max[1] - p[i].allocation[1];
        p[i].need[2] = p[i].max[2] - p[i].allocation[2];
    }

    printf("\nEnter the available vector: ");
    scanf("%d%d%d", &avail[0], &avail[1], &avail[2]);

    for (i = 0; i < n; i++)
        work[i] = avail[i];

    while (count != n)
    {
        count = 0;
        for (i = 0; i < n; i++)
        {
            flag = 1;
            if (p[i].finish == 0)
            {
                if (p[i].need[0] <= work[0] && p[i].need[1] <= work[1] && p[i].need[2] <= work[2])
                {
                    for (i = 0; i < 3; i++)
                        work[j] += p[i].allocation[j];
                    p[i].finish = 1;
                    sequence[k++] = i;
                    flag = 0;
                }
            }
        }
            if (flag == 1)
                count++;
        }

        
        count = 0;
        for (i = 0; i < n; i++)
        {
            if (p[i].finish == 1)
                count++;
        }


      
        printf("\nThe safe sequence:\t");
        if (count == n)
        {
            for (i = 0; i < k; i++);
            printf("%d\t", sequence[i]);
        }
        else
        {
            printf("system is not in a safe state\n\n");
        }
        return 0;
}
